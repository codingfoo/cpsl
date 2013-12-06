#include <string>
#include <iostream>

#include "../symbol_table/symbol_metadata.h"
#include "../symbol_table/symbol_table.h"
#include "program.h"
#include "read_statement.h"
#include "write_statement.h"
#include "expression_type.h"
#include "integer_constant.h"
#include "string_constant.h"
#include "identifier_expression.h"
#include "add_expression.h"
#include "sub_expression.h"
#include "mul_expression.h"
#include "div_expression.h"
#include "ast_node_visitor.h"
#include "emit_ast_node_visitor.h"

EmitASTNodeVisitor::EmitASTNodeVisitor()
{
  asmfile.open("./output.asm", std::ios::trunc);
  constantCounter = 0;
}

EmitASTNodeVisitor::~EmitASTNodeVisitor()
{
  asmfile.close();
}

void EmitASTNodeVisitor::emitHeader(std::string header)
{
  asmfile << '\t' << header << std::endl;
}

void EmitASTNodeVisitor::emitLabel(std::string label)
{
  asmfile << label << std::endl;
}

void EmitASTNodeVisitor::emitCode(std::string code)
{
  asmfile << '\t' << code << std::endl;
}

void EmitASTNodeVisitor::emitData(std::string label, Cpsl_Base_Type type, std::string data)
{
  std::string mips_type = "word";
  if(type == CPSL_STRING)
  {
    mips_type = "asciiz";
  }
  asmfile << label << ':' << '\t' << '.' << mips_type << '\t' << data << std::endl;
}

void EmitASTNodeVisitor::visit( Program & ast_node )
{
  emitHeader(".text");
  emitHeader(".globl  main");
  emitLabel("main:");

  ast_node.getStatementList().accept(*this);

  emitLabel("main_end:");
  emitCode("li $v0, 10  #Exit syscall");
  emitCode("syscall");

  emitHeader(".data");
  std::string label;
  std::string data;
  for (auto it = Symbol_Table::getInstance().getSymbolTable().begin(); it != Symbol_Table::getInstance().getSymbolTable().end(); it++) {
    label = it->second.label != "" ? it->second.label : it->first;
    emitData( label , it->second.type, it->second.value );
  }
}

void EmitASTNodeVisitor::visit( StatementList & ast_node )
{
  for (auto it = ast_node.getStatementList().begin(); it != ast_node.getStatementList().end(); it++) {
    (*it)->accept(*this);
  }
}

void EmitASTNodeVisitor::visit( Statement & ast_node )
{
  std::cerr << "Error: The Statement method should never be called!" << std::endl;
}

void EmitASTNodeVisitor::visit( ReadStatement & ast_node )
{
  if( ast_node.getIdentifier().getType() == INTEGER_EXPRESSION )
  {
    emitCode("li  $v0, 5  #Read integer"); // load appropriate system call code into register $v0
    emitCode("syscall"); // make syscall
    emitCode("sw  $v0, " + ast_node.getIdentifier().getValue());
  }
  else
  {
    emitCode("li  $v0, 12  #Read char"); // load appropriate system call code into register $v0
    emitCode("syscall"); // make syscall
    emitCode("sw  $v0, " + ast_node.getIdentifier().getValue());
  }
}

void EmitASTNodeVisitor::visit( WriteStatement & ast_node )
{
  /*
  print_int    1 $a0 = integer to be printed
  print_string 4 $a0 = address of string in memory
  */
  for (auto it = ast_node.getExpressionList().getExpressionList().begin(); it != ast_node.getExpressionList().getExpressionList().end(); it++) {
    (*it)->accept(*this);

    if( (*it)->getType() == INTEGER_EXPRESSION )
    {
      emitCode("li  $v0, 1  #Write integer"); // load appropriate system call code into register $v0
      emitCode("move  $a0, $t0"); // set up register corresponding to sys call
      emitCode("syscall"); // make syscall
    }

    if( (*it)->getType() == STRING_EXPRESSION )
    {
      emitCode("li  $v0, 4 #Write string"); // load appropriate system call code into register $v0
      // TODO: lookup label in symbol table
      emitCode("move  $a0, $t0"); // set up register corresponding to sys call
      emitCode("syscall"); // make syscall
    }
  }
}

void EmitASTNodeVisitor::visit( AddExpression & ast_node )
{
  ast_node.getLeft().accept(*this);

  emitCode("move  $t1,$t0");

  ast_node.getRight().accept(*this);

  emitCode("move  $t2,$t0");

  emitCode("add  $t0,$t1,$t2");
}

void EmitASTNodeVisitor::visit( SubExpression & ast_node )
{
  ast_node.getLeft().accept(*this);

  emitCode("move  $t1,$t0");

  ast_node.getRight().accept(*this);

  emitCode("move  $t2,$t0");

  emitCode("sub  $t0,$t1,$t2");
}

void EmitASTNodeVisitor::visit( MulExpression & ast_node )
{
  ast_node.getLeft().accept(*this);

  emitCode("move  $t1,$t0");

  ast_node.getRight().accept(*this);

  emitCode("move  $t2,$t0");

  emitCode("mul  $t0,$t1,$t2");
}

void EmitASTNodeVisitor::visit( DivExpression & ast_node )
{
  ast_node.getLeft().accept(*this);

  emitCode("move  $t1,$t0");

  ast_node.getRight().accept(*this);

  emitCode("move  $t2,$t0");

  emitCode("div  $t0,$t1,$t2");
}

void EmitASTNodeVisitor::visit( IntegerConstant & ast_node )
{
  if(ast_node.getType() == INTEGER_EXPRESSION)
  {
    emitCode("li  $t0, " + std::to_string(ast_node.getValue()) );
  }
}

void EmitASTNodeVisitor::visit( StringConstant & ast_node )
{
  Symbol_Metadata metadata = SymbolMetadataInitilizer;
  metadata.type = CPSL_STRING;
  metadata.label = "constant" + std::to_string(constantCounter++);
  metadata.value = ast_node.getValue();
  Symbol_Table::getInstance().addSymbol(ast_node.getValue(), metadata );
  emitCode("la  $t0, " + metadata.label );
}

void EmitASTNodeVisitor::visit( Identifier & ast_node ) {}
void EmitASTNodeVisitor::visit( CharConstant & ast_node ) {}
void EmitASTNodeVisitor::visit( StopStatement & ast_node ) {}
void EmitASTNodeVisitor::visit( ExpressionList & ast_node ) {}
void EmitASTNodeVisitor::visit( Expression & ast_node ) {}
void EmitASTNodeVisitor::visit( IdentifierExpression & ast_node ) {}


