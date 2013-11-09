#include "statement.h"
#include "ast_node_visitor.h"

Statement::Statement() {}
void Statement::accept(ASTNodeVisitor &v) { v.visit(*this); }
