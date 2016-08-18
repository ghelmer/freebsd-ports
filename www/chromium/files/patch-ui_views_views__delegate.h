--- ui/views/views_delegate.h.orig	2016-05-11 19:02:36 UTC
+++ ui/views/views_delegate.h
@@ -141,7 +141,7 @@ class VIEWS_EXPORT ViewsDelegate {
   // Returns true if the window passed in is in the Windows 8 metro
   // environment.
   virtual bool IsWindowInMetro(gfx::NativeWindow window) const;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_FREEBSD)
   virtual gfx::ImageSkia* GetDefaultWindowIcon() const;
 #endif
 
@@ -139,7 +139,7 @@
   // Returns the user-visible name of the application.
   virtual std::string GetApplicationName();
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   // Get a task runner suitable for posting initialization tasks for
   // Aura Linux accessibility.
   virtual scoped_refptr<base::TaskRunner>
