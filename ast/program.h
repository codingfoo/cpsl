#ifndef __PROGRAM_H
#define __PROGRAM_H

#include <string>
#include <utility>
#include <vector>

#include "ast_node.h"
#include "statement_list.h"
#include "routine_list.h"

typedef std::vector<std::pair<std::string, std::string>> Vars;

class Program : public ASTNode {
public:
  explicit Program(StatementList& statements, RoutineList& routines, Vars& vars) : _sl(statements), _rl(routines), _vars(vars) {}
  void accept(ASTNodeVisitor &v);
  StatementList& getStatementList();
  RoutineList& getRoutineList();
  Vars& getVars();
private:
  StatementList& _sl;
  RoutineList& _rl;
  Vars& _vars;
};

#endif // __PROGRAM_H
