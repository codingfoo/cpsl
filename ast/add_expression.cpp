#include "add_expression.h"
#include "ast_node_visitor.h"

AddExpression::AddExpression(Expression& left, Expression& right) : _left(left), _right(right) {}
void AddExpression::accept(ASTNodeVisitor &v) { v.visit(*this); }
Expression_Type AddExpression::getType()
{
  if(_left.getType() == _right.getType())
  {
    return _left.getType();
  }
  return INVALID_EXPRESSION;
}

Expression& AddExpression::getLeft()
{
  return _left;
}

Expression& AddExpression::getRight()
{
  return _right;
}
