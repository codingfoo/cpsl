

#include "function.h"
#include "ast_node_visitor.h"

Function::Function(Identifier& ident) : _ident(ident) {}
void Function::accept(ASTNodeVisitor &v) { v.visit(*this); }
std::string Function::getName()
{
  return _ident.getValue();
}
