#include "string_constant.h"
#include "ast_node_visitor.h"

void StringConstant::accept(ASTNodeVisitor &v) { v.visit(*this); }

Expression_Type StringConstant::getType()
{
  return STRING_EXPRESSION;
}

std::string StringConstant::getValue()
{
  return _value;
}

std::ostream& operator<< (std::ostream &out, const StringConstant &obj)
{
    out << obj._value;
    return out;
}
