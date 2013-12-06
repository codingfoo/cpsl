#ifndef __ROUTINE_LIST_H
#define __ROUTINE_LIST_H

#include <vector>

#include "ast_node.h"
#include "routine.h"

class RoutineList : public ASTNode {
public:
  explicit RoutineList();
  void push_back(Routine* routine);
  void accept(ASTNodeVisitor &v);
  std::vector<Routine*>& getRoutineList();
private:
  std::vector<Routine*> _list;
};

#endif // __ROUTINE_LIST_H
