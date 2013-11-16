#ifndef __SUB_EXPRESSION_H
#define __SUB_EXPRESSION_H

#include "expression.h"

class SubExpression : public Expression {
public:
  explicit SubExpression(Expression& left, Expression& right);
  void accept(ASTNodeVisitor &v);
  Expression_Type getType();
  Expression& getLeft();
  Expression& getRight();
private:
  Expression& _left;
  Expression& _right;
};

#endif // __SUB_EXPRESSION_H
