#include "string_constant.h"
#include "ast_node_visitor.h"

void StringConstant::accept(ASTNodeVisitor &v) { v.visit(*this); }

std::ostream& operator<< (std::ostream &out, const StringConstant &obj)
{
    out << obj._value;
    return out;
}
