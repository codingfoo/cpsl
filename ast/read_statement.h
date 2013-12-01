#ifndef __READ_STATEMENT_H
#define __READ_STATEMENT_H

#include <iostream>

#include "statement.h"
#include "identifier.h"

class ReadStatement : public Statement {
public:
  explicit ReadStatement(Identifier identifier) : _identifier(identifier) {}
  void accept(ASTNodeVisitor &v);
  Identifier getIdentifier();
private:
  Identifier _identifier;
};

#endif // __READ_STATEMENT_H
