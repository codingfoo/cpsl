#include "read_statement.h"
#include "ast_node_visitor.h"

void ReadStatement::accept(ASTNodeVisitor &v) { v.visit(*this); }
Identifier& ReadStatement::getIdentifier() { return _identifier; }
