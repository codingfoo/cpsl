#include "mul_expression.h"
#include "ast_node_visitor.h"

MulExpression::MulExpression(Expression& left, Expression& right) : _left(left), _right(right) {}
void MulExpression::accept(ASTNodeVisitor &v) { v.visit(*this); }
Expression_Type MulExpression::getType()
{
  if(_left.getType() == _right.getType())
  {
    return _left.getType();
  }
  return INVALID_EXPRESSION;
}

Expression& MulExpression::getLeft()
{
  return _left;
}

Expression& MulExpression::getRight()
{
  return _right;
}
