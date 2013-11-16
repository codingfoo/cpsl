#ifndef __MUL_EXPRESSION_H
#define __MUL_EXPRESSION_H

#include "expression.h"

class MulExpression : public Expression {
public:
  explicit MulExpression(Expression& left, Expression& right);
  void accept(ASTNodeVisitor &v);
  Expression_Type getType();
  Expression& getLeft();
  Expression& getRight();
private:
  Expression& _left;
  Expression& _right;
};

#endif // __MUL_EXPRESSION_H
