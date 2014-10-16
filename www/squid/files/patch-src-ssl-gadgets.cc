--- src/ssl/gadgets.cc	2014-10-07 14:11:12 +0000
+++ src/ssl/gadgets.cc	2014-10-16 16:34:34 +0000
@@ -312,7 +312,21 @@ 
                 if ((ext = X509_get_ext(cert.get(), p)) != NULL) {
                     ASN1_BIT_STRING *keyusage = (ASN1_BIT_STRING *)X509V3_EXT_d2i(ext);
                     ASN1_BIT_STRING_set_bit(keyusage, KeyEncipherment, 1);
-                    X509_EXTENSION_set_data( ext, (ASN1_OCTET_STRING*)keyusage );
+
+                    //Build the ASN1_OCTET_STRING
+                    const X509V3_EXT_METHOD *method = X509V3_EXT_get(ext);
+                    assert(method && method->it);
+                    unsigned char *ext_der = NULL;
+                    int ext_len = ASN1_item_i2d((ASN1_VALUE *)keyusage,
+                                                &ext_der, 
+                                                (const ASN1_ITEM *)ASN1_ITEM_ptr(method->it));
+
+                    ASN1_OCTET_STRING *ext_oct = M_ASN1_OCTET_STRING_new();
+                    ext_oct->data = ext_der;
+                    ext_oct->length = ext_len;
+                    X509_EXTENSION_set_data(ext, ext_oct);
+
+                    M_ASN1_OCTET_STRING_free(ext_oct);
                     ASN1_BIT_STRING_free(keyusage);
                 }
             }
