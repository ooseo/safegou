/* $Id$ */

#ifndef PHP_SAFEGOU_H
#define PHP_SAFEGOU_H

extern zend_module_entry safegou_module_entry;
#define phpext_safegou_ptr &safegou_module_entry

#define PHP_SAFEGOU_VERSION "0.0.1"

#ifdef PHP_WIN32
#   define PHP_SAFEGOU_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#   define PHP_SAFEGOU_API __attribute__ ((visibility("default")))
#else
#   define PHP_SAFEGOU_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#define SAFEGOU_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(safegou, v)

#if defined(ZTS) && defined(COMPILE_DL_SAFEGOU)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif	/* PHP_SAFEGOU_H */


