#include <iostream>

#include "program.h"
#include "ast_node_visitor.h"
#include "emit_ast_node_visitor.h"

EmitASTNodeVisitor::EmitASTNodeVisitor() {}

void EmitASTNodeVisitor::visit( Program & ast_node )
{
  std::cout << "Program" << std::endl;
  ast_node.getStatementList().accept(*this);
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
