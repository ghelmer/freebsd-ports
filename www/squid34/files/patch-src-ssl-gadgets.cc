--- src/ssl/gadgets.cc.ORIG	2014-06-25 09:41:39.000000000 -0500
+++ src/ssl/gadgets.cc	2014-08-22 12:42:26.101741408 -0500
@@ -249,11 +249,12 @@
     return certKey;
 }
 
-// Copy certificate extensions from cert to mimicCert.
+/// Copy certificate extensions from cert to mimicCert.
+/// Returns the number of extensions copied.
 // Currently only extensions which are reported by the users that required are
 // mimicked. More safe to mimic extensions would be added here if users request
 // them.
-static void
+static int
 mimicExtensions(Ssl::X509_Pointer & cert, Ssl::X509_Pointer const & mimicCert)
 {
     static int extensions[]= {
@@ -263,15 +264,50 @@
         0
     };
 
+    // key usage bit names
+    enum {
+        DigitalSignature,
+        NonRepudiation,
+        KeyEncipherment, // NSS requires for RSA but not EC
+        DataEncipherment,
+        KeyAgreement,
+        KeyCertificateSign,
+        CRLSign,
+        EncipherOnly,
+        DecipherOnly
+    };
+
+    int mimicAlgo = OBJ_obj2nid(mimicCert.get()->cert_info->key->algor->algorithm);
+
+    int added = 0;
     int nid;
     for (int i = 0; (nid = extensions[i]) != 0; ++i) {
         const int pos = X509_get_ext_by_NID(mimicCert.get(), nid, -1);
-        if (X509_EXTENSION *ext = X509_get_ext(mimicCert.get(), pos))
-            X509_add_ext(cert.get(), ext, -1);
+        if (X509_EXTENSION *ext = X509_get_ext(mimicCert.get(), pos)) {
+            // Mimic extension exactly.
+            if (X509_add_ext(cert.get(), ext, -1))
+                ++added;
+            if ( nid == NID_key_usage && mimicAlgo != NID_rsaEncryption ) {
+                // NSS does not requre the KeyEncipherment flag on EC keys
+                // but it does require it for RSA keys.  Since ssl-bump
+                // substitutes RSA keys for EC ones, we need to ensure that
+                // that the more stringent requirements are met.
+
+                const int p = X509_get_ext_by_NID(cert.get(), NID_key_usage, -1);
+                if ((ext = X509_get_ext(cert.get(), p)) != NULL) {
+                    ASN1_BIT_STRING *keyusage = (ASN1_BIT_STRING *)X509V3_EXT_d2i(ext);
+                    ASN1_BIT_STRING_set_bit(keyusage, KeyEncipherment, 1);
+                    X509_EXTENSION_set_data( ext, (ASN1_OCTET_STRING*)keyusage );
+                    ASN1_BIT_STRING_free(keyusage);
+                }
+            }
+        }
     }
 
     // We could also restrict mimicking of the CA extension to CA:FALSE
     // because Squid does not generate valid fake CA certificates.
+
+    return added;
 }
 
 static bool buildCertificate(Ssl::X509_Pointer & cert, Ssl::CertificateProperties const &properties)
@@ -331,22 +367,24 @@
             X509_alias_set1(cert.get(), alStr, alLen);
         }
 
+        int addedExtensions = 0;
+
         // Mimic subjectAltName unless we used a configured CN: browsers reject
         // certificates with CN unrelated to subjectAltNames.
         if (!properties.setCommonName) {
             int pos=X509_get_ext_by_NID (properties.mimicCert.get(), OBJ_sn2nid("subjectAltName"), -1);
             X509_EXTENSION *ext=X509_get_ext(properties.mimicCert.get(), pos);
             if (ext) {
-                X509_add_ext(cert.get(), ext, -1);
-                /* According the RFC 5280 using extensions requires version 3
-                   certificate.
-                   Set version value to 2 for version 3 certificates.
-                 */
-                X509_set_version(cert.get(), 2);
+                if (X509_add_ext(cert.get(), ext, -1))
+                    ++addedExtensions;
             }
         }
 
-        mimicExtensions(cert, properties.mimicCert);
+        addedExtensions += mimicExtensions(cert, properties.mimicCert);
+
+        // According to RFC 5280, using extensions requires v3 certificate.
+        if (addedExtensions)
+            X509_set_version(cert.get(), 2); // value 2 means v3
     }
 
     return true;
