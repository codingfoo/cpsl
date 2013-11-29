#include "div_expression.h"
#include "ast_node_visitor.h"

DivExpression::DivExpression(Expression& left, Expression& right) : _left(left), _right(right) {}
void DivExpression::accept(ASTNodeVisitor &v) { v.visit(*this); }
Expression_Type DivExpression::getType()
{
  if(_left.getType() == _right.getType())
  {
    return _left.getType();
  }
  return INVALID_EXPRESSION;
}

Expression& DivExpression::getLeft()
{
  return _left;
}

Expression& DivExpression::getRight()
{
  return _right;
}
