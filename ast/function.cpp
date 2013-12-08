#include "function.h"
#include "ast_node_visitor.h"

Function::Function(StatementList& statements, Vars vars)
{
  _sl = statements;
  _vars = vars;
}

void Function::accept(ASTNodeVisitor &v) { v.visit(*this); }

StatementList& Function::getStatementList()
{
  return _sl;
}

void Function::setIdentifier(Identifier & ident)
{
  _ident = ident;
}

std::string Function::getName()
{
  return _ident.getValue();
}

Vars& Function::getVars()
{
  return _vars;
}
