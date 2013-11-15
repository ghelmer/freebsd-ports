--- src/terminal/kbd.c.orig	Sun Nov 19 07:46:37 2006
+++ src/terminal/kbd.c	Thu Apr  5 10:20:53 2007
@@ -662,6 +662,13 @@
 
 		return -1;
 	}
+	if (itrm->in.queue.data[1] == '[' &&
+		itrm->in.queue.data[2] == 'Z') {
+		kbd.key = KBD_TAB;
+		kbd.modifier = KBD_MOD_SHIFT;
+		copy_struct(&ev->info.keyboard, &kbd);
+		return 3;
+	}
 
 	el = get_esc_code(itrm->in.queue.data, itrm->in.queue.len, &c, &v);
 #ifdef DEBUG_ITRM_QUEUE
