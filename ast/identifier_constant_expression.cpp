#include "identifier_constant_expression.h"
#include "ast_node_visitor.h"

IdentifierConstantExpression::IdentifierConstantExpression(Identifier& ident) : _ident(ident) {}
void IdentifierConstantExpression::accept(ASTNodeVisitor &v) { v.visit(*this); }
Expression_Type IdentifierConstantExpression::getType()
{
  return INVALID_EXPRESSION;
}

std::string IdentifierConstantExpression::getConstantValue()
{
  return _ident.getValue();
}
