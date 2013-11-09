#ifndef __PROGRAM_H
#define __PROGRAM_H

#include "ast_node.h"
#include "statement_list.h"

class Program : public ASTNode {
public:
  explicit Program(StatementList& statements) : _sl(statements) {}
  void accept(ASTNodeVisitor &v);
  StatementList& getStatementList();
private:
  StatementList& _sl;
};

#endif // __PROGRAM_H
