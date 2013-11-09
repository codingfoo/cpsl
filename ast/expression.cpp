#include "expression.h"
#include "ast_node_visitor.h"

Expression::Expression() {}
void Expression::accept(ASTNodeVisitor &v) { v.visit(*this); }
