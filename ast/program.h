#ifndef __PROGRAM_H
#define __PROGRAM_H

#include "ast_node.h"
#include "statement_list.h"
#include "routine_list.h"

class Program : public ASTNode {
public:
  explicit Program(StatementList& statements, RoutineList& routines) : _sl(statements), _rl(routines) {}
  void accept(ASTNodeVisitor &v);
  StatementList& getStatementList();
  RoutineList& getRoutineList();
private:
  StatementList& _sl;
  RoutineList& _rl;
};

#endif // __PROGRAM_H
