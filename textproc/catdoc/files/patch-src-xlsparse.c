--- src/xlsparse.c.orig	Mon Oct 10 15:33:02 2005
+++ src/xlsparse.c	Mon Oct 10 15:33:11 2005
@@ -28,7 +28,7 @@
 double date_shift = 25569.0;
 #define FLT_FORMAT(a,b,c) a #b c
 #define MK_FORMAT(x) FLT_FORMAT("%.",x,"g") 			
-char number_format[8]=MK_FORMAT(DBL_DIG);
+char number_format[8]=MK_FORMAT(20);
 
 void CleanUpFormatIdxUsed(void);
 
