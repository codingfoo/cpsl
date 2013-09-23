%{
#include <string>
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
%token NOT_EQUAL_OPERATOR
%token ASSIGNS_OPERATOR
%token LESS_THAN_OR_EQUAL_OPERATOR
%token GREATER_THAN_OR_EQUAL_OPERATOR
%token <identifier_ptr> IDENTIFIER
%token <char_val> CHAR_CONSTANT
%token <str_ptr> STRING_CONSTANT
%token <int_val> INTEGER_CONSTANT

%%

program: constant_decl
         type_decl
         var_decl
         routine
         block
         '.'

constant_decl: CONST_KEYWORD const_statement
               |

const_statement: IDENTIFIER '=' const_expression ';'
                 | const_statement IDENTIFIER '=' const_expression ';'

type_decl: TYPE_KEYWORD type_statement
           |

type_statement: IDENTIFIER '=' type ';'
                | type_statement IDENTIFIER '=' type ';'

type: simple_type
      | record_type
      | array_type

simple_type: IDENTIFIER

record_type: RECORD_KEYWORD record_type_statement END_KEYWORD

record_type_statement: ident_list ':' type ';'
                       | record_type_statement ident_list ':' type ';'
                       |

ident_list: IDENTIFIER
            | ident_list ',' IDENTIFIER

array_type: ARRAY_KEYWORD '[' const_expression ':' const_expression ']' OF_KEYWORD type

var_decl:

routine: routine procedure_decl
         | routine function_decl
         |

procedure_decl: PROCEDURE_KEYWORD

function_decl: FUNCTION_KEYWORD

block: BEGIN_KEYWORD END_KEYWORD

const_expression: INTEGER_CONSTANT
                  | IDENTIFIER

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

  while( yyparse() ) {}

  return 0;
}
