#ifndef __FUNCTION_H
#define __FUNCTION_H

#include <string>

#include "routine.h"
#include "identifier.h"
#include "statement_list.h"

class Function : public Routine {
public:
  explicit Function(Identifier& ident, StatementList& statements);
  void accept(ASTNodeVisitor &v);
  StatementList& getStatementList();
  std::string getName();
private:
  Identifier _ident;
  StatementList& _sl;
};

#endif // __FUNCTION_H
