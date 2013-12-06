#include "program.h"
#include "ast_node_visitor.h"

void Program::accept(ASTNodeVisitor &v) { v.visit(*this); }
StatementList& Program::getStatementList()
{
  return _sl;
}

RoutineList& Program::getRoutineList()
{
  return _rl;
}
