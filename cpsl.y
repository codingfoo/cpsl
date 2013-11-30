%verbose
%debug
%error-verbose

%code requires {

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
#include "ast/ast_node.h"
#include "ast/program.h"
#include "ast/statement_list.h"
#include "ast/statement.h"
#include "ast/write_statement.h"
#include "ast/read_statement.h"
#include "ast/stop_statement.h"
#include "ast/expression_list.h"
#include "ast/expression.h"
#include "ast/add_expression.h"
#include "ast/sub_expression.h"
#include "ast/mul_expression.h"
#include "ast/div_expression.h"
#include "ast/constant.h"
#include "ast/integer_constant.h"
#include "ast/char_constant.h"
#include "ast/string_constant.h"
#include "ast/identifier.h"
#include "ast/emit_ast_node_visitor.h"

#endif

}


%{
extern "C" int yylex(void);
extern "C" int yyparse();
#include <stdio.h>
extern "C" FILE *yyin;
void yyerror(const char *s);
%}


%{
#include <cstring>
#include "vector"
#include "ast/ast_node.h"
#include "ast/program.h"
#include "ast/statement_list.h"
#include "ast/statement.h"
#include "ast/write_statement.h"
#include "ast/read_statement.h"
#include "ast/stop_statement.h"
#include "ast/expression_list.h"
#include "ast/expression.h"
#include "ast/add_expression.h"
#include "ast/sub_expression.h"
#include "ast/mul_expression.h"
#include "ast/div_expression.h"
#include "ast/constant.h"
#include "ast/integer_constant.h"
#include "ast/char_constant.h"
#include "ast/string_constant.h"
#include "ast/identifier.h"
#include "ast/emit_ast_node_visitor.h"

Program* root;
%}


%union {
  Program* program;
  StatementList* statement_list;
  Statement* statement;
  ReadStatement* read_statement;
  WriteStatement* write_statement;
  StopStatement* stop_statment;
  ExpressionList* expression_list;
  Expression* expression;
  Constant* constant;
  IntegerConstant* integer_constant;
  CharConstant* char_constant;
  StringConstant* string_constant;
  Identifier* identifier;
}


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

%token <identifier> IDENTIFIER
%token <char_constant> CHAR_CONSTANT
%token <string_constant> STRING_CONSTANT
%token <integer_constant> INTEGER_CONSTANT

/* <type> non-terminal */
%type <program> program
%type <statement_list> statement_sequence
%type <statement_list> block
%type <statement> statement
%type <stop_statement> stopstatement
%type <read_statement> readstatement
%type <write_statement> writestatement
%type <expression_list> inner_write
%type <expression> expression
%type <expression> const_expression

/* highest precedence -> lowest on the screen */
%left '|'
%left '&'
%right '~'
%nonassoc '=' NOT_EQUAL_OPERATOR '<' LESS_THAN_OR_EQUAL_OPERATOR '>' GREATER_THAN_OR_EQUAL_OPERATOR
%left '+' '-'
%left '*' '/' '%'
%right NEG

%start program

%%

program: constant_decl
         type_decl
         var_decl
         routine
         block
         '.' { $$ = new Program(*$5); root = $$; }
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

procedure_ident: PROCEDURE_KEYWORD IDENTIFIER
                 ;

procedure_decl: procedure_ident '(' formal_parameters ')' ';' FORWARD_KEYWORD ';'
                | procedure_ident '(' formal_parameters ')' ';' body ';'
                ;

function_ident: FUNCTION_KEYWORD IDENTIFIER
                ;

function_decl: function_ident '(' formal_parameters ')' ':' type ';' FORWARD_KEYWORD ';'
               | function_ident '(' formal_parameters ')' ':' type ';' body ';'
               ;

formal_parameters: VAR_KEYWORD ident_list ':' type
                   | ident_list ':' type
                   | formal_parameters ident_list ':' type
                   |
                   ;

body: constant_decl type_decl var_decl block ;

block: BEGIN_KEYWORD statement_sequence END_KEYWORD { $$ = $2; }
       ;

statement_sequence: statement { $$ = new StatementList(); $$->push_back($1); }
                    | statement_sequence ';' statement {$$->push_back($3);}
                    ;

statement: assignment
           | ifstatement
           | whilestatement
           | repeatstatement
           | forstatement
           | stopstatement { $$ = new StopStatement(); }
           | returnstatement
           | readstatement
           | writestatement { $$ = $1; }
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
            ;

writestatement: WRITE_KEYWORD '(' inner_write ')' { $$ = new WriteStatement(*$3); }
              ;

inner_write: expression { $$ = new ExpressionList(); $$->push_back($1); }
             | inner_write ',' expression { $$->push_back($3); }
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
            | expression '+' expression { $$ = new AddExpression(*$1, *$3); }
            | expression '-' expression { $$ = new SubExpression(*$1, *$3); }
            | expression '*' expression { $$ = new MulExpression(*$1, *$3); }
            | expression '/' expression { $$ = new DivExpression(*$1, *$3); }
            | expression '%' expression
            | '~' expression
            | '-' expression  %prec NEG
            | '(' expression ')'
            | IDENTIFIER '(' inside_expr ')'
            | CHR_KEYWORD '(' expression ')'
            | ORD_KEYWORD '(' expression ')'
            | PRED_KEYWORD '(' expression ')'
            | SUCC_KEYWORD '(' expression ')'
            | const_expression { $$ = $1; }
            | lvalue
            ;

inside_expr: expression
             | inside_expr ',' expression
             |
             ;

const_expression: INTEGER_CONSTANT { $$ = $1; }
                  | CHAR_CONSTANT
                  | STRING_CONSTANT
                  ;

lvalue: IDENTIFIER lvalue_sub

lvalue_sub: lvalue_sub '.' IDENTIFIER
            | lvalue_sub '[' expression ']'
            |
            ;

%%

int main(int argc, char* argv[]) {
  ++argv, --argc; // ignore program name
  bool verbose(false);

  if ( argc > 0 )
  {
    if( strncmp(argv[0], "-v", 2) == 0 )
    {
      ++argv;
      --argc; // Remove flag
      verbose = true;
    }
  }

  if ( argc > 0 )
  {
    yyin = fopen( argv[0], "r" );
  }
  else
  {
    yyin = stdin;
  }
  // yydebug = 1;

  yyparse();

  EmitASTNodeVisitor vs;

  root->accept(vs);

  if( verbose )
  {
    //std::cout << "Identifier" << "  Offset" << std::endl;
    //std::cout << Symbol_Table::getInstance();
  }

  return 0;
}
