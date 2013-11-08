#include "write_statement.h"
#include "ast_node_visitor.h"

WriteStatement::WriteStatement(ASTNode&) {}
WriteStatement::WriteStatement() {}
void WriteStatement::accept(ASTNodeVisitor &v) { v.visit(*this); }
