%{
#include <string>
#include "cpsl.h"
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

%option debug
%option nodefault
%option warn

%x IN_CHAR_CONSTANT

%%

[array|ARRAY] {return(ARRAY_KEYWORD);}
[begin|BEGIN] {return(BEGIN_KEYWORD);}
[chr|CHR] {return(CHR_KEYWORD);}
[const|CONST] {return(CONST_KEYWORD);}
[do|DO] {return(DO_KEYWORD);}
[end|END] {return(END_KEYWORD);}
[for|FOR] {return(FOR_KEYWORD);}
[forward|FORWARD] {return(FORWARD_KEYWORD);}
[ord|ORD] {return(ORD_KEYWORD);}
[pred|PRED] {return(PRED_KEYWORD);}
[procedure|PROCEDURE] {return(PROCEDURE_KEYWORD);}
[return|RETURN] {return(RETURN_KEYWORD);}
[stop|STOP] {return(STOP_KEYWORD);}
[succ|SUCC] {return(SUCC_KEYWORD);}
[until|UNTIL] {return(UNTIL_KEYWORD);}
[var|VAR] {return(VAR_KEYWORD);}
[while|WHILE] {return(WHILE_KEYWORD);}
[downto|DOWNTO] {return(DOWNTO_KEYWORD);}
[function|FUNCTION] {return(FUNCTION_KEYWORD);}
[read|READ] {return(READ_KEYWORD);}
[then|THEN] {return(THEN_KEYWORD);}
[write|WRITE] {return(WRITE_KEYWORD);}

[[:alpha:]][[:alnum:]_]* {yylval.identifier_ptr = strdup(yytext); return(IDENTIFIER);}

"+"  {return(PLUS_OPERATOR);}
"-"  {return(MINUS_OPERATOR);}
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

0x[0-9a-fA-F]* {yylval.int_val = std::stoi(yytext, 0, 0); return(INTEGER_CONSTANT);}
0[0-7]* {yylval.int_val = std::stoi(yytext,0, 0); return(INTEGER_CONSTANT);}
[0-9][0-9]* {yylval.int_val = std::stoi(yytext, 0, 0); return(INTEGER_CONSTANT);}

'           { BEGIN(IN_CHAR_CONSTANT); }
<IN_CHAR_CONSTANT>{
\n           {yyerror("Newline is not allowed in a character constant. Constant maybe unclosed."); BEGIN INITIAL;}
[[:print:]]' {yylval.char_val = yytext[0]; BEGIN INITIAL; return(CHAR_CONSTANT);}
. {yyerror("Malformed character constant."); BEGIN INITIAL;}
}

\"[[:print:]]*\" {yylval.str_ptr = strdup(yytext); return(STRING_CONSTANT);}

"$".*[\n]     // Ignore one-line comments

[ \t]      // Ignore whitespace
\n              yylineno++;

'' {yyerror("Illegal character constant: A Character constant must not be blank.");}

. {yyerror("Unrecognized character.");}

%%

int main(int argc, char* argv[]) {
  ++argv, --argc; // ignore program name
  if ( argc > 0 )
  {
    yyin = fopen( argv[0], "r" );
  }
  else
  {
    yyin = stdin;
  }

  while( yylex() ) {}

  return 0;
}
