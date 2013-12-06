#include "if_statement.h"
#include "ast_node_visitor.h"

void IfStatement::accept(ASTNodeVisitor &v) { v.visit(*this); }

Expression& IfStatement::getExpression()
{
  return _expression;
}

StatementList& IfStatement::getStatements()
{
  return _sl;
}
