#include "stop_statement.h"
#include "ast_node_visitor.h"

StopStatement::StopStatement() {}
void StopStatement::accept(ASTNodeVisitor &v) { v.visit(*this); }
