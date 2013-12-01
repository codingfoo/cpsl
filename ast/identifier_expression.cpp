#include "identifier_expression.h"
#include "ast_node_visitor.h"

IdentifierExpression::IdentifierExpression(Identifier& ident) : _ident(ident) {}
void IdentifierExpression::accept(ASTNodeVisitor &v) { v.visit(*this); }
Expression_Type IdentifierExpression::getType()
{
  return INVALID_EXPRESSION;
}
