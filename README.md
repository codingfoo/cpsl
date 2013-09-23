cpsl compiler
=============

Special Cases
=============
error message for newline in string
error message no double quote in string constant(no escape)


"this is "not" a string"
operators just return the symbol
single quote in char constant
\<any char> in char constant
\n \r \b \t \f
\<any char> in string constant
\n \r \b \t \f
extra leading zeros in integer constants
leading zeros with a 8 or a 9( they would have to be decimal, consider them fail?)
$ char in string not match comment
error message for newline(non escaped) in char constant

