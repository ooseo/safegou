/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_safegou.h"
#include "core.h"

PHP_FUNCTION(safegou_encode)
{
    zend_string *strg;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "S", &strg) == FAILURE) {
        return;
    }

    /* If encoded */
    if (!memcmp(ZSTR_VAL(strg), safegou_header, sizeof(safegou_header))) {
        RETURN_FALSE;
    }

    char *t = emalloc(sizeof(safegou_header) + ZSTR_LEN(strg));
    memcpy(t, safegou_header, sizeof(safegou_header));
    if (ZSTR_LEN(strg) > 0) {
        safegou_encode(ZSTR_VAL(strg), ZSTR_LEN(strg));
        memcpy(t + sizeof(safegou_header), ZSTR_VAL(strg), ZSTR_LEN(strg));
    }

    RETURN_STR(zend_string_init(t, sizeof(safegou_header) + ZSTR_LEN(strg), 0));
}

PHP_MINIT_FUNCTION(safegou)
{
    old_compile_file = zend_compile_file;
    zend_compile_file = cgi_compile_file;
    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(safegou)
{
    zend_compile_file = old_compile_file;
    return SUCCESS;
}

PHP_RINIT_FUNCTION(safegou)
{
#if defined(COMPILE_DL_SAFEGOU) && defined(ZTS)
    ZEND_TSRMLS_CACHE_UPDATE();
#endif
    return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(safegou)
{
    return SUCCESS;
}

PHP_MINFO_FUNCTION(safegou)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "Safegou Support", "enabled");
    php_info_print_table_row(2, "Version", PHP_SAFEGOU_VERSION);
    php_info_print_table_row(2, "Open Sourced By", "htmln.com");
    php_info_print_table_end();
}

const zend_function_entry safegou_functions[] = {
    PHP_FE(safegou_encode,	NULL)
    PHP_FE_END
};

zend_module_entry safegou_module_entry = {
    STANDARD_MODULE_HEADER,
    "safegou",
    safegou_functions,
    PHP_MINIT(safegou),
    PHP_MSHUTDOWN(safegou),
    NULL,
    NULL,
    PHP_MINFO(safegou),
    PHP_SAFEGOU_VERSION,
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_SAFEGOU
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(safegou)
#endif

