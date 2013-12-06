#include "integer_constant.h"
#include "ast_node_visitor.h"

void IntegerConstant::accept(ASTNodeVisitor &v) { v.visit(*this); }

Expression_Type IntegerConstant::getType()
{
  return INTEGER_EXPRESSION;
}

int IntegerConstant::getValue()
{
  return _value;
}

std::string IntegerConstant::getConstantValue()
{
  return std::to_string(_value);
}

std::ostream& operator<< (std::ostream &out, const IntegerConstant &obj)
{
    out << obj._value;
    return out;
}
