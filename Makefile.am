SUBDIRS = . lib phpext

bootstrap-phpext:
	@cd phpext; phpize; ./configure

cleanup-phpext:
	rm -rf  \
	phpext/.libs/ \
	phpext/autom4te.cache/ \
	phpext/build/ \
	phpext/include/ \
	phpext/modules/ \
	phpext/config.h \
	phpext/.deps \
	phpext/Makefile.fragments \
	phpext/Makefile.global \
	phpext/Makefile.objects \
	phpext/CREDITS \
	phpext/EXPERIMENTAL \
	phpext/Makefile.global \
	phpext/acinclude.m4 \
	phpext/aclocal.m4 \
	phpext/config.guess  \
	phpext/config.h.in \
	phpext/config.nice  \
	phpext/config.sub  \
	phpext/config.log  \
	phpext/config.status \
	phpext/configure  \
	phpext/configure.in \
	phpext/install-sh \
	phpext/libtool \
	phpext/ltmain.sh \
	phpext/missing \
	phpext/mkinstalldirs \
	phpext/trim_utf8.la \
	phpext/trim_utf8.lo
