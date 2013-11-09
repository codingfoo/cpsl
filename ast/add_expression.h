#ifndef __ADD_EXPRESSION_H
#define __ADD_EXPRESSION_H

#include "expression.h"

class AddExpression : public Expression {
public:
  explicit AddExpression(Expression& left, Expression& right);
  void accept(ASTNodeVisitor &v);
};

#endif // __ADD_EXPRESSION_H
