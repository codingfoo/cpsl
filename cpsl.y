%verbose
%debug
%error-verbose
%{
#include "cpsl.h"
%}

%{
extern "C"
{
  int yylex(void);
}
extern "C" int yyparse();
extern "C" FILE *yyin;

void yyerror(const char *s);
%}

%union {
  int int_val;
  char char_val;
  char *str_ptr;
  char *identifier_ptr;
};

%token ARRAY_KEYWORD
%token BEGIN_KEYWORD
%token CHR_KEYWORD
%token CONST_KEYWORD
%token DO_KEYWORD
%token ELSE_KEYWORD
%token ELSEIF_KEYWORD
%token IF_KEYWORD
%token OF_KEYWORD
%token RECORD_KEYWORD
%token REPEAT_KEYWORD
%token TO_KEYWORD
%token TYPE_KEYWORD
%token END_KEYWORD
%token FOR_KEYWORD
%token FORWARD_KEYWORD
%token ORD_KEYWORD
%token PRED_KEYWORD
%token PROCEDURE_KEYWORD
%token RETURN_KEYWORD
%token STOP_KEYWORD
%token SUCC_KEYWORD
%token UNTIL_KEYWORD
%token VAR_KEYWORD
%token WHILE_KEYWORD
%token DOWNTO_KEYWORD
%token FUNCTION_KEYWORD
%token READ_KEYWORD
%token THEN_KEYWORD
%token WRITE_KEYWORD
%token ASSIGNS_OPERATOR
%token NOT_EQUAL_OPERATOR
%token LESS_THAN_OR_EQUAL_OPERATOR
%token GREATER_THAN_OR_EQUAL_OPERATOR
%token <identifier_ptr> IDENTIFIER
%token <char_val> CHAR_CONSTANT
%token <str_ptr> STRING_CONSTANT
%token <int_val> INTEGER_CONSTANT

%right NEG
%left '*' '/' '%'
%left '+' '-'
%nonassoc '=' NOT_EQUAL_OPERATOR '<' LESS_THAN_OR_EQUAL_OPERATOR '>' GREATER_THAN_OR_EQUAL_OPERATOR
%right '~'
%left '&'
%left '|'

%%

program: constant_decl
         type_decl
         var_decl
         routine
         block
         '.'
         ;

constant_decl: CONST_KEYWORD const_statement
               |
               ;

const_statement: IDENTIFIER '=' const_expression ';'
                 | const_statement IDENTIFIER '=' const_expression ';'
                 ;

type_decl: TYPE_KEYWORD type_statement
           |
           ;

type_statement: IDENTIFIER '=' type ';'
                | type_statement IDENTIFIER '=' type ';'
                ;

type: simple_type
      | record_type
      | array_type
      ;

simple_type: IDENTIFIER
             ;

record_type: RECORD_KEYWORD record_type_statement END_KEYWORD
             ;

ident_list_decl: ident_list ':' type ';';

record_type_statement: ident_list_decl
                       | record_type_statement ident_list_decl
                       |
                       ;


ident_list: IDENTIFIER
            | ident_list ',' IDENTIFIER
            ;

array_type: ARRAY_KEYWORD '[' const_expression ':' const_expression ']' OF_KEYWORD type
            ;

var_decl: VAR_KEYWORD var_statement
          |
          ;

var_statement: ident_list_decl
               | var_statement ident_list_decl
               ;

routine: procedure_decl
         | function_decl
         | routine procedure_decl
         | routine function_decl
         |
         ;

procedure_decl: PROCEDURE_KEYWORD IDENTIFIER '(' formal_parameters ')' ';' procedure_decl_postfix
                ;

procedure_decl_postfix: FORWARD_KEYWORD ';'
                        | body ';'
                        ;

function_decl: FUNCTION_KEYWORD IDENTIFIER '(' formal_parameters ')' ':' type ';' FORWARD_KEYWORD ';'
               | FUNCTION_KEYWORD IDENTIFIER '(' formal_parameters ')' ':' type ';' body ';'
               ;

formal_parameters: VAR_KEYWORD ident_list ':' type
                   | ident_list ':' type
                   | formal_parameters ident_list ':' type
                   |
                   ;

body: constant_decl type_decl var_decl block ;

block: BEGIN_KEYWORD statement_sequence END_KEYWORD ;

statement_sequence: statement
                    | statement_sequence ';' statement
                    ;

statement: assignment
           | ifstatement
           | whilestatement
           | repeatstatement
           | forstatement
           | stopstatement
           | returnstatement
           | readstatement
           | writestatement
           | procedurecall
           | nullstatement
           ;

assignment: lvalue ASSIGNS_OPERATOR expression

ifstatement: initial_if else_if else END_KEYWORD ;

initial_if: IF_KEYWORD expression THEN_KEYWORD statement_sequence ;

else_if: ELSEIF_KEYWORD expression THEN_KEYWORD statement_sequence
         | else_if ELSEIF_KEYWORD expression THEN_KEYWORD statement_sequence
         |
         ;

else: ELSE_KEYWORD statement_sequence
      |
      ;

whilestatement: WHILE_KEYWORD expression DO_KEYWORD statement_sequence END_KEYWORD;

repeatstatement: REPEAT_KEYWORD statement_sequence UNTIL_KEYWORD expression;

forstatement: FOR_KEYWORD IDENTIFIER ASSIGNS_OPERATOR expression TO_KEYWORD expression DO_KEYWORD statement_sequence END_KEYWORD
              | FOR_KEYWORD IDENTIFIER ASSIGNS_OPERATOR expression DOWNTO_KEYWORD expression DO_KEYWORD statement_sequence END_KEYWORD
              ;


stopstatement: STOP_KEYWORD;

returnstatement: RETURN_KEYWORD
                 | RETURN_KEYWORD expression
                 ;

readstatement: READ_KEYWORD '(' inner_read ')';

inner_read: lvalue
            | inner_read ',' lvalue

writestatement: WRITE_KEYWORD '(' inner_write ')';

inner_write: expression
             | inner_write ',' expression
             |
             ;

procedurecall: IDENTIFIER '(' inner_write ')';

nullstatement: ;

expression: expression '|' expression
            | expression '&' expression
            | expression '=' expression
            | expression NOT_EQUAL_OPERATOR expression
            | expression LESS_THAN_OR_EQUAL_OPERATOR expression
            | expression GREATER_THAN_OR_EQUAL_OPERATOR expression
            | expression '<' expression
            | expression '>' expression
            | expression '+' expression
            | expression '-' expression
            | expression '*' expression
            | expression '/' expression
            | expression '%' expression
            | '~' expression
            | '-' expression  %prec NEG
            | '(' expression ')'
            | IDENTIFIER '(' inside_expr ')'
            | CHR_KEYWORD '(' expression ')'
            | ORD_KEYWORD '(' expression ')'
            | PRED_KEYWORD '(' expression ')'
            | SUCC_KEYWORD '(' expression ')'
            | const_expression
            ;

inside_expr: expression
             | inside_expr ',' expression
             |
             ;

const_expression: INTEGER_CONSTANT
                  | CHAR_CONSTANT
                  | STRING_CONSTANT
                  | lvalue
                  ;

lvalue: IDENTIFIER lvalue_sub

lvalue_sub: lvalue_sub '.' IDENTIFIER
            | lvalue_sub '[' expression ']'
            |
            ;

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
  // yydebug = 1;


  do {
    yyparse();
  } while (!feof(yyin));

  return 0;
}
