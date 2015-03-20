--- src/ssl/certificate_db.cc.ORIG	2015-03-20 12:49:00.000000000 -0500
+++ src/ssl/certificate_db.cc	2015-03-20 12:50:14.000000000 -0500
@@ -55,7 +55,7 @@
 #if _SQUID_WINDOWS_
     if (!LockFile(hFile, 0, 0, 1, 0))
 #else
-    if (lockf(fd, F_LOCK, 0) != 0)
+    if (flock(fd, LOCK_EX) != 0)
 #endif
         throw std::runtime_error("Failed to get a lock of " + filename);
 }
@@ -70,7 +70,7 @@
     }
 #else
     if (fd != -1) {
-        lockf(fd, F_ULOCK, 0);
+        flock(fd, LOCK_EX);
         close(fd);
         fd = -1;
     }
