#include "gt_expression.h"
#include "ast_node_visitor.h"

GTExpression::GTExpression(Expression& left, Expression& right) : _left(left), _right(right) {}
void GTExpression::accept(ASTNodeVisitor &v) { v.visit(*this); }
Expression_Type GTExpression::getType()
{
  return BOOLEAN_EXPRESSION;
}

Expression& GTExpression::getLeft()
{
  return _left;
}

Expression& GTExpression::getRight()
{
  return _right;
}
