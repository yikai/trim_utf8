dnl $Id$
dnl config.m4 for extension trim_utf8

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(trim_utf8, for trim_utf8 support,
dnl Make sure that the comment is aligned:
dnl [  --with-trim_utf8             Include trim_utf8 support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(trim_utf8, whether to enable trim_utf8 support,
dnl Make sure that the comment is aligned:
[  --enable-trim_utf8           Enable trim_utf8 support])

if test "$PHP_TRIM_UTF8" != "no"; then
  dnl Write more examples of tests here...

  # --with-trim_utf8 -> check with-path
  SEARCH_PATH="/usr/local /usr ../../lib"     # you might want to change this
  SEARCH_FOR="trim_utf8.h"  # you most likely want to change this
  if test -r $PHP_TRIM_UTF8/$SEARCH_FOR; then # path given as parameter
    TRIM_UTF8_DIR=$PHP_TRIM_UTF8
  else # search default path list
    AC_MSG_CHECKING([for trim_utf8 files in default path])
    for i in $SEARCH_PATH ; do
      if test -r $i/$SEARCH_FOR; then
        TRIM_UTF8_DIR=$i
        AC_MSG_RESULT(found in $i)
      fi
    done
  fi
  
  if test -z "$TRIM_UTF8_DIR"; then
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([Please reinstall the trim_utf8 distribution])
  fi

  # --with-trim_utf8 -> add include path
  PHP_ADD_INCLUDE($TRIM_UTF8_DIR)

  # --with-trim_utf8 -> check for lib and symbol presence
  LIBNAME=trim_utf8 # you may want to change this
  LIBSYMBOL=trim    # you most likely want to change this 

#  PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
#  [
    PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $TRIM_UTF8_DIR, TRIM_UTF8_SHARED_LIBADD)
    AC_DEFINE(HAVE_TRIM_UTF8LIB,1,[ ])
#  ],[
#    AC_MSG_ERROR([wrong trim_utf8 lib version or lib not found])
#  ],[
#    -L$TRIM_UTF8_DIR -l$LIBNAME
#  ])
  
  CFLAGS="$CLFAFS -Wall -Werror -g -O2"
  PHP_SUBST(TRIM_UTF8_SHARED_LIBADD)

  PHP_NEW_EXTENSION(trim_utf8, trim_utf8.c, $ext_shared)
fi
