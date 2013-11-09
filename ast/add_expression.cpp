#include "add_expression.h"
#include "ast_node_visitor.h"

AddExpression::AddExpression(Expression& left, Expression& right) {}
void AddExpression::accept(ASTNodeVisitor &v) { v.visit(*this); }
