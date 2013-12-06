#ifndef __IF_STATEMENT_H
#define __IF_STATEMENT_H

#include <iostream>

#include "statement.h"
#include "expression_list.h"
#include "statement_list.h"

class IfStatement : public Statement {
public:
  explicit IfStatement(Expression& expression, StatementList& statements) : _el(expression), _sl(statements) {}
  void accept(ASTNodeVisitor &v);
private:
  Expression& _el;
  StatementList& _sl;
};

#endif // __IF_STATEMENT_H
