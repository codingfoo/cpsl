#include "statement_list.h"
#include "ast_node_visitor.h"

StatementList::StatementList() {}
void StatementList::accept(ASTNodeVisitor &v) { v.visit(*this); }
void StatementList::push_back(Statement* statement) { _list.push_back( statement ); }
std::vector<Statement*>& StatementList::getStatementList(){ return _list; }
