#include "program.h"
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

void EmitASTNodeVisitor::visit( Program & ast_node )
{
  emitHeader(".globl main");
  emitLabel("main:");

  ast_node.getStatementList().accept(*this);

  emitCode("li $v0, 10");
  emitCode("syscall");
}

void EmitASTNodeVisitor::visit( StatementList & ast_node )
{
  std::cout << "StatementList"<< std::endl;
}

void EmitASTNodeVisitor::visit( IntegerConstant & ast_node ) {}
void EmitASTNodeVisitor::visit( WriteStatement & ast_node )
{
  std::cout << "WriteStatement"<< std::endl;
}
void EmitASTNodeVisitor::visit( CharConstant & ast_node ) {}
void EmitASTNodeVisitor::visit( StringConstant & ast_node ) {}
void EmitASTNodeVisitor::visit( Identifier & ast_node ) {}
void EmitASTNodeVisitor::visit( StopStatement & ast_node ) {}
void EmitASTNodeVisitor::visit( Statement & ast_node ) {}
