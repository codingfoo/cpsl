#ifndef __NULL_STATEMENT_H
#define __NULL_STATEMENT_H

#include "statement.h"

class NullStatement : public Statement {
public:
  explicit NullStatement();
  void accept(ASTNodeVisitor &v);
};

#endif // __NULL_STATEMENT_H
