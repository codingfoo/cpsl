#include "char_constant.h"
#include "ast_node_visitor.h"

void CharConstant::accept(ASTNodeVisitor &v) { v.visit(*this); }

Expression_Type CharConstant::getType()
{
  return CHAR_EXPRESSION;
}

std::string CharConstant::getConstantValue()
{
  return std::to_string(_value);
}

std::ostream& operator<< (std::ostream &out, const CharConstant &obj)
{
    out << obj._value;
    return out;
}
