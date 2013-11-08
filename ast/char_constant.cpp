#include "char_constant.h"
#include "ast_node_visitor.h"

void CharConstant::accept(ASTNodeVisitor &v) { v.visit(*this); }

std::ostream& operator<< (std::ostream &out, const CharConstant &obj)
{
    out << obj._value;
    return out;
}
