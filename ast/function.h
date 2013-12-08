#ifndef __FUNCTION_H
#define __FUNCTION_H

#include <string>
#include <utility>
#include <vector>

#include "routine.h"
#include "identifier.h"
#include "statement_list.h"

typedef std::vector<std::pair<std::string, std::string>> Vars;

class Function : public Routine {
public:
  explicit Function(StatementList& statements, Vars vars);
  void accept(ASTNodeVisitor &v);
  StatementList& getStatementList();
  std::string getName();
  void setIdentifier(Identifier & ident);
  void setArgs(Vars args);
  Vars& getArgs();
  Vars& getVars();
private:
  Identifier _ident;
  StatementList _sl;
  Vars _vars;
  Vars _args;
};

#endif // __FUNCTION_H
