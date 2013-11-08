#ifndef __WRITE_STATEMENT_H
#define __WRITE_STATEMENT_H

#include <iostream>

#include "statement.h"
#include "write_statement.h"
#include "integer_constant.h"

class WriteStatement : public Statement {
public:
  explicit WriteStatement();
  explicit WriteStatement( IntegerConstant &foo );
  explicit WriteStatement( ASTNode &foo );
  void accept(ASTNodeVisitor &v);
};

#endif // __WRITE_STATEMENT_H
