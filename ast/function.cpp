#include "function.h"
#include "ast_node_visitor.h"

Function::Function(Identifier& ident, StatementList& statements) : _ident(ident), _sl(statements) {}
void Function::accept(ASTNodeVisitor &v) { v.visit(*this); }

StatementList& Function::getStatementList()
{
  return _sl;
}
std::string Function::getName()
{
  return _ident.getValue();
}
