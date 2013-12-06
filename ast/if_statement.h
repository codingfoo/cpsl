#ifndef __IF_STATEMENT_H
#define __IF_STATEMENT_H

#include <iostream>

#include "statement.h"

class IfStatement : public Statement {
public:
  explicit IfStatement() {}
  void accept(ASTNodeVisitor &v);
private:
};

#endif // __IF_STATEMENT_H
