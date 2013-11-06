%option nodefault
%option noyywrap
%option warn
/*%option debug*/

%{
#include <string>
#include "cpsl.tab.h"

#define YY_DECL extern "C" int yylex(void)

void yyerror(const char *s)
{
      printf("%d: %s\n", yylineno, s);
}

%}

%x IN_CHAR_CONSTANT

%%

array|ARRAY {return(ARRAY_KEYWORD);}
begin|BEGIN {return(BEGIN_KEYWORD);}
chr|CHR {return(CHR_KEYWORD);}
const|CONST {return(CONST_KEYWORD);}
do|DO {return(DO_KEYWORD);}
downto|DOWNTO {return(DOWNTO_KEYWORD);}
else|ELSE {return(ELSE_KEYWORD);}
elseif|ELSEIF {return(ELSEIF_KEYWORD);}
end|END {return(END_KEYWORD);}
for|FOR {return(FOR_KEYWORD);}
forward|FORWARD {return(FORWARD_KEYWORD);}
function|FUNCTION {return(FUNCTION_KEYWORD);}
if|IF {return(IF_KEYWORD);}
of|OF {return(OF_KEYWORD);}
ord|ORD {return(ORD_KEYWORD);}
pred|PRED {return(PRED_KEYWORD);}
procedure|PROCEDURE {return(PROCEDURE_KEYWORD);}
read|READ {return(READ_KEYWORD);}
record|RECORD {return(RECORD_KEYWORD);}
repeat|REPEAT {return(REPEAT_KEYWORD);}
return|RETURN {return(RETURN_KEYWORD);}
stop|STOP {return(STOP_KEYWORD);}
succ|SUCC {return(SUCC_KEYWORD);}
then|THEN {return(THEN_KEYWORD);}
to|TO {return(TO_KEYWORD);}
type|TYPE {return(TYPE_KEYWORD);}
until|UNTIL {return(UNTIL_KEYWORD);}
var|VAR {return(VAR_KEYWORD);}
while|WHILE {return(WHILE_KEYWORD);}
write|WRITE {return(WRITE_KEYWORD);}

[[:alpha:]][[:alnum:]_]* {yylval.identifier_ptr = strdup(yytext); return(IDENTIFIER);}

"+"  {return(yytext[0]);}
"-"  {return(yytext[0]);}
"∗"  {return(yytext[0]);}
"/"  {return(yytext[0]);}
"&"  {return(yytext[0]);}
"|"  {return(yytext[0]);}
"~"  {return(yytext[0]);}
"="  {return(yytext[0]);}
"<"  {return(yytext[0]);}
">"  {return(yytext[0]);}
"."  {return(yytext[0]);}
","  {return(yytext[0]);}
":"  {return(yytext[0]);}
";"  {return(yytext[0]);}
"("  {return(yytext[0]);}
")"  {return(yytext[0]);}
"["  {return(yytext[0]);}
"]"  {return(yytext[0]);}
"%"  {return(yytext[0]);}
">=" {return(GREATER_THAN_OR_EQUAL_OPERATOR);}
"<=" {return(LESS_THAN_OR_EQUAL_OPERATOR);}
"<>" {return(NOT_EQUAL_OPERATOR);}
":=" {return(ASSIGNS_OPERATOR);}

0x[0-9a-fA-F]* {yylval.int_val = std::stoi(yytext, 0, 0); return(INTEGER_CONSTANT);}
0[0-7]*        {yylval.int_val = std::stoi(yytext, 0, 0); return(INTEGER_CONSTANT);}
[0-9][0-9]*    {yylval.int_val = std::stoi(yytext, 0, 0); return(INTEGER_CONSTANT);}

'           { BEGIN(IN_CHAR_CONSTANT); }
<IN_CHAR_CONSTANT>{
\\n'          {yylval.char_val = '\n'; BEGIN(INITIAL); return(CHAR_CONSTANT);}
\\r'          {yylval.char_val = '\r'; BEGIN(INITIAL); return(CHAR_CONSTANT);}
\\b'          {yylval.char_val = '\b'; BEGIN(INITIAL); return(CHAR_CONSTANT);}
\\t'          {yylval.char_val = '\t'; BEGIN(INITIAL); return(CHAR_CONSTANT);}
\\f'          {yylval.char_val = '\f'; BEGIN(INITIAL); return(CHAR_CONSTANT);}
[[:print:]]'  {yylval.char_val = yytext[0]; BEGIN(INITIAL); return(CHAR_CONSTANT);}
'             {yyerror("Invalid character constant: A character constant must not be empty."); BEGIN(INITIAL);}
\n            {yyerror("Invalid Character constant: Newline is not allowed in a character constant. Constant may be unclosed."); yylineno++; BEGIN(INITIAL);}
.             {yyerror("Invalid Character constant: Invalid character or more than a single represented character."); BEGIN(INITIAL);}
}

\"[^\"\r\n]*\" {yylval.str_ptr = strdup(yytext); return(STRING_CONSTANT);}

"$".*[\n]     yylineno++;// Ignore one-line comments

[ ]        // Ignore whitespace
\t         // Ignore whitespace
\n         yylineno++;

. {yyerror("Unrecognized character.");}

%%
