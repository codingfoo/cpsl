#include "routine.h"
#include "ast_node_visitor.h"

Routine::Routine() {}
void Routine::accept(ASTNodeVisitor &v) { v.visit(*this); }
