dnl $Id$
dnl config.m4 for extension safegou

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(safegou, for safegou support,
dnl Make sure that the comment is aligned:
dnl [  --with-safegou             Include safegou support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(safegou, whether to enable safegou support,
Make sure that the comment is aligned:
[  --enable-safegou           Enable safegou support])

if test "$PHP_SAFEGOU" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-safegou -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/safegou.h"  # you most likely want to change this
  dnl if test -r $PHP_SAFEGOU/$SEARCH_FOR; then # path given as parameter
  dnl   SAFEGOU_DIR=$PHP_SAFEGOU
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for safegou files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       SAFEGOU_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$SAFEGOU_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the safegou distribution])
  dnl fi

  dnl # --with-safegou -> add include path
  dnl PHP_ADD_INCLUDE($SAFEGOU_DIR/include)

  dnl # --with-safegou -> check for lib and symbol presence
  dnl LIBNAME=safegou # you may want to change this
  dnl LIBSYMBOL=safegou # you most likely want to change this

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $SAFEGOU_DIR/$PHP_LIBDIR, SAFEGOU_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_SAFEGOULIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong safegou lib version or lib not found])
  dnl ],[
  dnl   -L$SAFEGOU_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(SAFEGOU_SHARED_LIBADD)

  PHP_NEW_EXTENSION(safegou, safegou.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
