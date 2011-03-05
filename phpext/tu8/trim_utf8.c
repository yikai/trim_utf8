
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_trim_utf8.h"

#include "trim_utf8.h"

/* If you declare any globals in php_trim_utf8.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(trim_utf8)
*/

/* True global resources - no need for thread safety here */
/* static int le_trim_utf8; */

/* {{{ trim_utf8_functions[]
 *
 * Every user visible function must have an entry in trim_utf8_functions[].
 */
const zend_function_entry trim_utf8_functions[] = {
    PHP_FE(tu8_strip_space,    NULL)
    PHP_FE(tu8_pack_space,    NULL)
    PHP_FE(tu8_ltrim,    NULL)
    PHP_FE(tu8_rtrim,    NULL)
    PHP_FE(tu8_trim,    NULL)
    {NULL, NULL, NULL}    /* Must be the last line in trim_utf8_functions[] */
};
/* }}} */

/* {{{ trim_utf8_module_entry
 */
zend_module_entry trim_utf8_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    "trim_utf8",
    trim_utf8_functions,
    PHP_MINIT(trim_utf8),
    PHP_MSHUTDOWN(trim_utf8),
    PHP_RINIT(trim_utf8),        /* Replace with NULL if there's nothing to do at request start */
    PHP_RSHUTDOWN(trim_utf8),    /* Replace with NULL if there's nothing to do at request end */
    PHP_MINFO(trim_utf8),
#if ZEND_MODULE_API_NO >= 20010901
    "0.1", /* Replace with version number for your extension */
#endif
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_TRIM_UTF8
ZEND_GET_MODULE(trim_utf8)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("trim_utf8.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_trim_utf8_globals, trim_utf8_globals)
    STD_PHP_INI_ENTRY("trim_utf8.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_trim_utf8_globals, trim_utf8_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_trim_utf8_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_trim_utf8_init_globals(zend_trim_utf8_globals *trim_utf8_globals)
{
    trim_utf8_globals->global_value = 0;
    trim_utf8_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(trim_utf8)
{
    /* If you have INI entries, uncomment these lines 
    REGISTER_INI_ENTRIES();
    */
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(trim_utf8)
{
    /* uncomment this line if you have INI entries
    UNREGISTER_INI_ENTRIES();
    */
    return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(trim_utf8)
{
    return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(trim_utf8)
{
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(trim_utf8)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "trim_utf8 support", "enabled");
    php_info_print_table_end();

    /* Remove comments if you have entries in php.ini
    DISPLAY_INI_ENTRIES();
    */
}
/* }}} */

/* {{{ proto string tu8_strip_space(string str)
    */
PHP_FUNCTION(tu8_strip_space)
{
    char *str = NULL;
    int argc = ZEND_NUM_ARGS();
    int str_len;
    int ret_str_len = 0;

    if (zend_parse_parameters(argc TSRMLS_CC, "s", &str, &str_len) == FAILURE) {
        return;
    }

    RETVAL_STRINGL(str, str_len, 1);

    if ( (ret_str_len = strip_space((unsigned char*)str, (unsigned char*) Z_STRVAL_P(return_value), str_len)) == 0) {
        RETURN_FALSE;
    }

    Z_STRLEN_P(return_value) = ret_str_len;
    return;
}
/* }}} */

/* {{{ proto string tu8_pack_space(string str)
    */
PHP_FUNCTION(tu8_pack_space)
{
    char *str = NULL;
    int argc = ZEND_NUM_ARGS();
    int str_len;
    int ret_str_len = 0;

    if (zend_parse_parameters(argc TSRMLS_CC, "s", &str, &str_len) == FAILURE) {
        return;
    }

    RETVAL_STRINGL(str, str_len, 1);

    if ( (ret_str_len = pack_space((unsigned char*)str, (unsigned char*) Z_STRVAL_P(return_value), str_len)) == 0) {
        RETURN_FALSE;
    }

    Z_STRLEN_P(return_value) = ret_str_len;
    return;
}
/* }}} */

/* {{{ proto string tu8_ltrim(string str)
    */
PHP_FUNCTION(tu8_ltrim)
{
    char *str = NULL;
    int argc = ZEND_NUM_ARGS();
    int str_len;
    int ret_str_len = 0;

    if (zend_parse_parameters(argc TSRMLS_CC, "s", &str, &str_len) == FAILURE) {
        return;
    }

    RETVAL_STRINGL(str, str_len, 1);

    if ( (ret_str_len = ltrim((unsigned char*)str, (unsigned char*) Z_STRVAL_P(return_value), str_len)) == 0) {
        RETURN_FALSE;
    }

    Z_STRLEN_P(return_value) = ret_str_len;
    return;
}
/* }}} */

/* {{{ proto string tu8_rtrim(string str)
    */
PHP_FUNCTION(tu8_rtrim)
{
    char *str = NULL;
    int argc = ZEND_NUM_ARGS();
    int str_len;
    int ret_str_len = 0;

    if (zend_parse_parameters(argc TSRMLS_CC, "s", &str, &str_len) == FAILURE) {
        return;
    }

    RETVAL_STRINGL(str, str_len, 1);

    if ( (ret_str_len = rtrim((unsigned char*)str, (unsigned char*) Z_STRVAL_P(return_value), str_len)) == 0) {
        RETURN_FALSE;
    }

    Z_STRLEN_P(return_value) = ret_str_len;
    return;
}
/* }}} */

/* {{{ proto string tu8_trim(string str)
    */
PHP_FUNCTION(tu8_trim)
{
    char *str = NULL;
    int argc = ZEND_NUM_ARGS();
    int str_len;
    int ret_str_len = 0;

    if (zend_parse_parameters(argc TSRMLS_CC, "s", &str, &str_len) == FAILURE) {
        return;
    }

    RETVAL_STRINGL(str, str_len, 1);

    if ( (ret_str_len = trim((unsigned char*)str, (unsigned char*) Z_STRVAL_P(return_value), str_len)) == 0) {
        RETURN_FALSE;
    }

    Z_STRLEN_P(return_value) = ret_str_len;
    return;
}
/* }}} */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
