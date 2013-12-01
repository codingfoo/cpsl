CPSL Compiler
=============

Tasks
=====
expressions
  :=
  >
  <>
  =
  -
  +
  <
  <=
symbol table( how to handle scopes? )
statements
  read
  write
  stop
control structures
  for
  if
  repeat
  while
udt
function calls
move main into seperate file
add options parser(gnuopt)
     verbose
     debug
     in file / std in (set yyin rather than )
     out file
mixed pointers


Special Cases For Lexer
=======================
TODO: error message for newline in string
TODO: error message no double quote in string constant(no escape)

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

Symbol Table
============
symbol table stack

symbol table(map<<string>, shared_ptr<symbol>>)

symbols
  type
    array
    record
    simple type
  function / procedure
  variable symbols
  const

– Scope 0 – predefined identifiers in the language
– Scope 1 – global (main) level
– Scope 2 – inside procedures and functions

symbol : metadata( type scope offset value )

base types: boolean, integer, char, string
