--- src/FwdState.cc.ORIG	2014-01-22 10:25:27.000000000 -0600
+++ src/FwdState.cc	2014-01-22 10:28:06.000000000 -0600
@@ -728,6 +728,9 @@
                 }
             }
 
+	    debugs(81, DBG_IMPORTANT, "negotiateSSL: FD " << fd <<
+		   ": SSL failure for request host " << request->GetHost());
+
             ErrorState *const anErr = makeConnectingError(ERR_SECURE_CONNECT_FAIL);
             anErr->xerrno = sysErrNo;
             anErr->detail = errDetails;
@@ -748,8 +751,11 @@
             serverBump->serverCert.reset(SSL_get_peer_certificate(ssl));
 
             // remember validation errors, if any
-            if (Ssl::CertErrors *errs = static_cast<Ssl::CertErrors *>(SSL_get_ex_data(ssl, ssl_ex_index_ssl_errors)))
+            if (Ssl::CertErrors *errs = static_cast<Ssl::CertErrors *>(SSL_get_ex_data(ssl, ssl_ex_index_ssl_errors))) {
                 serverBump->sslErrors = cbdataReference(errs);
+		debugs(81, DBG_IMPORTANT, "negotiateSSL: FD " << fd <<
+		       ": SSL validation failure for request host " << request->GetHost());
+	    }
         }
     }
 
