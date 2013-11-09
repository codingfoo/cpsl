#include "expression_list.h"
#include "ast_node_visitor.h"

ExpressionList::ExpressionList() {}
void ExpressionList::accept(ASTNodeVisitor &v) { v.visit(*this); }
void ExpressionList::push_back(Expression* expression) { _list.push_back( expression ); }
std::vector<Expression*>& ExpressionList::getExpressionList(){ return _list; }
