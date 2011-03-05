<?php
$br = (php_sapi_name() == "cli")? "":"<br>";

if(!extension_loaded('trim_utf8')) {
    dl('modules/trim_utf8.' . PHP_SHLIB_SUFFIX);
}

$module = 'trim_utf8';
$functions = get_extension_funcs($module);
echo "Functions available in the test extension:$br\n";
foreach($functions as $func) {
    echo $func."$br\n";
}
echo "$br\n";
