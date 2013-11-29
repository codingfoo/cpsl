#ifndef __DIV_EXPRESSION_H
#define __DIV_EXPRESSION_H

#include "expression.h"

class DivExpression : public Expression {
public:
  explicit DivExpression(Expression& left, Expression& right);
  void accept(ASTNodeVisitor &v);
  Expression_Type getType();
  Expression& getLeft();
  Expression& getRight();
private:
  Expression& _left;
  Expression& _right;
};

#endif // __DIV_EXPRESSION_H
