Other needed libs:
 - cairo (git://anongit.freedesktop.org/git/cairo)
 - pango (git://git.gnome.org/pango)
 - pixman (git://anongit.freedesktop.org/git/pixman)
 - glib (git://git.gnome.org/glib)
 - libpng (git://libpng.git.sourceforge.net/gitroot/libpng)
 - zlib (http://zlib.net/)
 
 Don't forget to apply patchs from the patchs folder if needed, plus:
 
    -Pango: Generate files needed by compilation (you can also get them from the Win32 source package on http://www.gtk.org/download/win32.php)
            (module-defs-lang.c, module-defs-win32.c, module-defs.h, pango-enum-types.c, pango-enum-types.h)