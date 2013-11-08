#ifndef __STOP_STATEMENT_H
#define __STOP_STATEMENT_H

#include "statement.h"

class StopStatement : public Statement {
public:
  explicit StopStatement();
  void accept(ASTNodeVisitor &v);
};

#endif // __STOP_STATEMENT_H
