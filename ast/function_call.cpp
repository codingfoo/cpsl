#include "function_call.h"
#include "ast_node_visitor.h"

FunctionCall::FunctionCall(Identifier& ident) : _ident(ident) {}
void FunctionCall::accept(ASTNodeVisitor &v) { v.visit(*this); }

std::string FunctionCall::getName()
{
  return _ident.getValue();
}
