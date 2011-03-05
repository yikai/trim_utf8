SUBDIRS = . tu8

all-am: bootstrap-phpext
clean-am: cleanup-phpext

bootstrap-phpext:
	@cd tu8; phpize; ./configure

cleanup-phpext:
	rm -rf  \
	tu8/.libs/ \
	tu8/autom4te.cache/ \
	tu8/build/ \
	tu8/include/ \
	tu8/modules/ \
	tu8/config.h \
	tu8/.deps \
	tu8/Makefile.fragments \
	tu8/Makefile.global \
	tu8/Makefile.objects \
	tu8/CREDITS \
	tu8/EXPERIMENTAL \
	tu8/Makefile.global \
	tu8/acinclude.m4 \
	tu8/aclocal.m4 \
	tu8/config.guess  \
	tu8/config.h.in \
	tu8/config.nice  \
	tu8/config.sub  \
	tu8/config.log  \
	tu8/config.status \
	tu8/configure  \
	tu8/configure.in \
	tu8/install-sh \
	tu8/libtool \
	tu8/ltmain.sh \
	tu8/missing \
	tu8/mkinstalldirs \
	tu8/trim_utf8.la \
	tu8/trim_utf8.lo
