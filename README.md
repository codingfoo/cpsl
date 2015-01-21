CPSL Compiler for CS5300
========================

Special Cases For Lexer
=======================

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

Scope 0 – predefined identifiers in the language

Scope 1 – global (main) level

Scope 2 – inside procedures and functions

symbol : metadata( type scope offset value )

base types: boolean, integer, char, string


Scratch
=======
```
if( global )
{
  Symbol_Metadata metadata = SymbolMetadataInitilizer;
  metadata.label = $2->getValue();
  metadata.value = $4->getConstantValue();
  Symbol_Table::getInstance().addSymbol($2->getValue(), metadata );
  //Symbol_Table::getInstance().addSymbol($1->getValue(), $3->getValue());
$$ = $1;
}
```
