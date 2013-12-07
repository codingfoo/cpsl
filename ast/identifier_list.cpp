#include "identifier_list.h"
#include "ast_node_visitor.h"

IdentifierList::IdentifierList() {}
void IdentifierList::accept(ASTNodeVisitor &v) { v.visit(*this); }
void IdentifierList::push_back(Identifier* identifier) { _list.push_back( identifier ); }
std::vector<Identifier*>& IdentifierList::getIdentifierList(){ return _list; }
