
#ifndef PHP_TRIM_UTF8_H
#define PHP_TRIM_UTF8_H

extern zend_module_entry trim_utf8_module_entry;
#define phpext_trim_utf8_ptr &trim_utf8_module_entry

#ifdef PHP_WIN32
#	define PHP_TRIM_UTF8_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_TRIM_UTF8_API __attribute__ ((visibility("default")))
#else
#	define PHP_TRIM_UTF8_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(trim_utf8);
PHP_MSHUTDOWN_FUNCTION(trim_utf8);
PHP_RINIT_FUNCTION(trim_utf8);
PHP_RSHUTDOWN_FUNCTION(trim_utf8);
PHP_MINFO_FUNCTION(trim_utf8);

PHP_FUNCTION(tu8_strip_space);
PHP_FUNCTION(tu8_pack_space);
PHP_FUNCTION(tu8_ltrim);
PHP_FUNCTION(tu8_rtrim);
PHP_FUNCTION(tu8_trim);

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(trim_utf8)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(trim_utf8)
*/

/* In every utility function you add that needs to use variables 
   in php_trim_utf8_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as TRIM_UTF8_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define TRIM_UTF8_G(v) TSRMG(trim_utf8_globals_id, zend_trim_utf8_globals *, v)
#else
#define TRIM_UTF8_G(v) (trim_utf8_globals.v)
#endif

#endif	/* PHP_TRIM_UTF8_H */

