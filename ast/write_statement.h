#ifndef __WRITE_STATEMENT_H
#define __WRITE_STATEMENT_H

#include <iostream>

#include "statement.h"
#include "expression_list.h"

class WriteStatement : public Statement {
public:
  explicit WriteStatement(ExpressionList& expressions) : _el(expressions) {}
  void accept(ASTNodeVisitor &v);
  ExpressionList& getExpressionList();
private:
  ExpressionList& _el;
};

#endif // __WRITE_STATEMENT_H
