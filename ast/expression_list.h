#ifndef __EXPRESSION_LIST_H
#define __EXPRESSION_LIST_H

#include <vector>

#include "expression.h"

class ExpressionList : public ASTNode {
public:
  explicit ExpressionList();
  void push_back(Expression* expression);
  void accept(ASTNodeVisitor &v);
  std::vector<Expression*>& getExpressionList();
private:
  std::vector<Expression*> _list;
};

#endif // __EXPRESSION_LIST_H
