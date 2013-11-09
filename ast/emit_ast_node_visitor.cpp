#include <string>

#include "program.h"
#include "write_statement.h"
#include "expression_type.h"
#include "integer_constant.h"
#include "add_expression.h"
#include "ast_node_visitor.h"
#include "emit_ast_node_visitor.h"

EmitASTNodeVisitor::EmitASTNodeVisitor()
{
  asmfile.open("./output.asm", std::ios::trunc);
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

void EmitASTNodeVisitor::emitData(std::string label, std::string type, std::string data)
{
  asmfile << label << ':' << '\t' << '.' << type << '\t' << data << std::endl;
}

void EmitASTNodeVisitor::visit( Program & ast_node )
{
  emitHeader(".data");
  emitHeader(".text");
  emitLabel("main:");

  ast_node.getStatementList().accept(*this);

  emitCode("li $v0, 10");
  emitCode("syscall");
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
      emitCode("li  $v0, 1"); // load appropriate system call code into register $v0
      emitCode("move  $a0, $t0"); // set up register corresponding to sys call
      emitCode("syscall"); // make syscall
    }

    if( (*it)->getType() == STRING_EXPRESSION )
    {
      emitCode("li  $v0, 4"); // load appropriate system call code into register $v0
      // TODO: lookup label in symbol table
      emitCode("move  $a0, $t0"); // set up register corresponding to sys call
      emitCode("syscall"); // make syscall
    }
  }
}

void EmitASTNodeVisitor::visit( StopStatement & ast_node ) {}

void EmitASTNodeVisitor::visit( ExpressionList & ast_node ) {}
void EmitASTNodeVisitor::visit( Expression & ast_node ) {}
void EmitASTNodeVisitor::visit( AddExpression & ast_node )
{
  ast_node.getLeft().accept(*this);

  emitCode("add  $t1,$t0,$zero");

  ast_node.getRight().accept(*this);

  emitCode("add  $t2,$t0,$zero");

  emitCode("add  $t0,$t1,$t2");
}

void EmitASTNodeVisitor::visit( IntegerConstant & ast_node )
{
  if(ast_node.getType() == INTEGER_EXPRESSION)
  {
    emitCode("li  $t0, " + std::to_string(ast_node.getValue()) );
  }
}
void EmitASTNodeVisitor::visit( CharConstant & ast_node ) {}
void EmitASTNodeVisitor::visit( StringConstant & ast_node ) {}
void EmitASTNodeVisitor::visit( Identifier & ast_node ) {}

