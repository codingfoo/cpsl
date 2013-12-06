#ifndef __GT_EXPRESSION_H
#define __GT_EXPRESSION_H

#include "expression.h"

class GTExpression : public Expression {
public:
  explicit GTExpression(Expression& left, Expression& right);
  void accept(ASTNodeVisitor &v);
  Expression_Type getType();
  Expression& getLeft();
  Expression& getRight();
private:
  Expression& _left;
  Expression& _right;
};

#endif // __GT_EXPRESSION_H
