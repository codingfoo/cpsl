%{
#include <stdio.h>
#include <stdlib.h>
%}

%{
extern "C"
{
  int yylex(void);
}
%}


%{
typedef union {
  int int_val;
  char char_val;
  char *str_ptr;
  char *identifier_ptr;
} YYSTYPE;

extern "C"
{
  YYSTYPE yylval;
}
%}

%{
void yyerror(const char *s)
{
      printf("%d: %s\n", yylineno, s);
}
%}

%{
enum terminals {
ARRAY_KEYWORD,
BEGIN_KEYWORD,
CHR_KEYWORD,
CONST_KEYWORD,
DO_KEYWORD,
END_KEYWORD,
FOR_KEYWORD,
FORWARD_KEYWORD,
ORD_KEYWORD,
PRED_KEYWORD,
PROCEDURE_KEYWORD,
RETURN_KEYWORD,
STOP_KEYWORD,
SUCC_KEYWORD,
UNTIL_KEYWORD,
VAR_KEYWORD,
WHILE_KEYWORD,
DOWNTO_KEYWORD,
FUNCTION_KEYWORD,
READ_KEYWORD,
THEN_KEYWORD,
WRITE_KEYWORD,
IDENTIFIER,
PLUS_OPERATOR,
MINUS_OPERATOR,
ASTERISK_OPERATOR,
SLASH_OPERATOR,
AMPERSAND_OPERATOR,
BAR_OPERATOR,
TILDE_OPERATOR,
EQUAL_OPERATOR,
NOT_EQUAL_OPERATOR,
LESS_THAN_OPERATOR,
LESS_THAN_OR_EQUAL_OPERATOR,
GREATER_THAN_OPERATOR,
GREATER_THAN_OR_EQUAL_OPERATOR,
PERIOD_OPERATOR,
COMMA_OPERATOR,
COLON_OPERATOR,
SEMICOLON_OPERATOR,
OPEN_PAREN_OPERATOR,
CLOSE_PAREN_OPERATOR,
OPEN_BRACKET_OPERATOR,
CLOSE_BRACKET_OPERATOR,
ASSIGNS_OPERATOR,
PERCENT_OPERATOR,
INTEGER_CONSTANT,
CHAR_CONSTANT,
STRING_CONSTANT
};
%}

%%

array|ARRAY {return(ARRAY_KEYWORD);}
begin|BEGIN {return(BEGIN_KEYWORD);}
chr|CHR {return(CHR_KEYWORD);}
const|CONST {return(CONST_KEYWORD);}
do|DO {return(DO_KEYWORD);}
end|END {return(END_KEYWORD);}
for|FOR {return(FOR_KEYWORD);}
forward|FORWARD {return(FORWARD_KEYWORD);}
ord|ORD {return(ORD_KEYWORD);}
pred|PRED {return(PRED_KEYWORD);}
procedure|PROCEDURE {return(PROCEDURE_KEYWORD);}
return|RETURN {return(RETURN_KEYWORD);}
stop|STOP {return(STOP_KEYWORD);}
succ|SUCC {return(SUCC_KEYWORD);}
until|UNTIL {return(UNTIL_KEYWORD);}
var|VAR {return(VAR_KEYWORD);}
while|WHILE {return(WHILE_KEYWORD);}
downto|DOWNTO {return(DOWNTO_KEYWORD);}
function|FUNCTION {return(FUNCTION_KEYWORD);}
read|READ {return(READ_KEYWORD);}
then|THEN {return(THEN_KEYWORD);}
write|WRITE {return(WRITE_KEYWORD);}

[a-zA-Z][a-zA-Z0-9_]* {yylval.identifier_ptr = strdup(yytext); return(IDENTIFIER);}

"+"  {return(PLUS_OPERATOR);}
"−"  {return(MINUS_OPERATOR);}
"∗"  {return(ASTERISK_OPERATOR);}
"/"  {return(SLASH_OPERATOR);}
"&"  {return(AMPERSAND_OPERATOR);}
"|"  {return(BAR_OPERATOR);}
"~"  {return(TILDE_OPERATOR);}
"="  {return(EQUAL_OPERATOR);}
"<>" {return(NOT_EQUAL_OPERATOR);}
"<"  {return(LESS_THAN_OPERATOR);}
"<=" {return(LESS_THAN_OR_EQUAL_OPERATOR);}
">"  {return(GREATER_THAN_OPERATOR);}
">=" {return(GREATER_THAN_OR_EQUAL_OPERATOR);}
"."  {return(PERIOD_OPERATOR);}
","  {return(COMMA_OPERATOR);}
":"  {return(COLON_OPERATOR);}
";"  {return(SEMICOLON_OPERATOR);}
"("  {return(OPEN_PAREN_OPERATOR);}
")"  {return(CLOSE_PAREN_OPERATOR);}
"["  {return(OPEN_BRACKET_OPERATOR);}
"]"  {return(CLOSE_BRACKET_OPERATOR);}
":=" {return(ASSIGNS_OPERATOR);}
"%"  {return(PERCENT_OPERATOR);}

0x[1-9A-F][0-9A-F]* {yylval.int_val = atoi(yytext); printf("%d", yylval.int_val); return(INTEGER_CONSTANT);}
0[1-7][0-7]* {yylval.int_val = atoi(yytext); return(INTEGER_CONSTANT);}
[0-9][0-9]* {yylval.int_val = atoi(yytext); return(INTEGER_CONSTANT);}

'[a-zA-Z]' {yylval.char_val = yytext[1]; return(CHAR_CONSTANT);}

\"[a-zA-Z]*\" {yylval.str_ptr = strdup(yytext); return(STRING_CONSTANT);}

"$".*[\n]     // Ignore one-line comments

[ \t\n]+      // Ignore whitespace

'' {yyerror("Illegal character constant: A Character constant must not be blank.");}

. {yyerror("ILLEGAL CHARACTER");}

%%

int main(int argc, char* argv[]) {
  yylex();
  return 0;
}