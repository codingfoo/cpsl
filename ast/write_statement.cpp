#include "write_statement.h"
#include "ast_node_visitor.h"

void WriteStatement::accept(ASTNodeVisitor &v) { v.visit(*this); }
ExpressionList& WriteStatement::getExpressionList() { return _el; }
