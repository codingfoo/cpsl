#include "identifier.h"
#include "ast_node_visitor.h"

void Identifier::accept(ASTNodeVisitor &v) { v.visit(*this); }

Expression_Type Identifier::getType()
{
  return INTEGER_EXPRESSION; //TODO: delegate to symbol table
}

std::string Identifier::getValue()
{
  return _value;
}

std::ostream& operator<< (std::ostream &out, const Identifier &obj)
{
    out << obj._value;
    return out;
}
