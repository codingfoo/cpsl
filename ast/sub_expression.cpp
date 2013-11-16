#include "sub_expression.h"
#include "ast_node_visitor.h"

SubExpression::SubExpression(Expression& left, Expression& right) : _left(left), _right(right) {}
void SubExpression::accept(ASTNodeVisitor &v) { v.visit(*this); }
Expression_Type SubExpression::getType()
{
  if(_left.getType() == _right.getType())
  {
    return _left.getType();
  }
  return INVALID_EXPRESSION;
}

Expression& SubExpression::getLeft()
{
  return _left;
}

Expression& SubExpression::getRight()
{
  return _right;
}
