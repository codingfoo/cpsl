#include "routine_list.h"
#include "ast_node_visitor.h"

RoutineList::RoutineList() {}
void RoutineList::accept(ASTNodeVisitor &v) { v.visit(*this); }
void RoutineList::push_back(Routine* routine) { _list.push_back( routine ); }
std::vector<Routine*>& RoutineList::getRoutineList(){ return _list; }
