#ifndef __STATEMENT_LIST_H
#define __STATEMENT_LIST_H

#include <vector>

#include "statement.h"

class StatementList : public ASTNode {
public:
  explicit StatementList();
  void push_back(Statement* statement);
  void accept(ASTNodeVisitor &v);
  std::vector<Statement*>& getStatementList(){ return _list; }
private:
  std::vector<Statement*> _list;
};

#endif // __STATEMENT_LIST_H
