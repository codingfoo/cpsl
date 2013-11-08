#include "identifier.h"
#include "ast_node_visitor.h"

void Identifier::accept(ASTNodeVisitor &v) { v.visit(*this); }

std::ostream& operator<< (std::ostream &out, const Identifier &obj)
{
    out << obj._value;
    return out;
}
