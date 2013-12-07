#include "null_statement.h"
#include "ast_node_visitor.h"

NullStatement::NullStatement() {}
void NullStatement::accept(ASTNodeVisitor &v) { v.visit(*this); }
