#ifndef __IDENTIFIER_EXPRESSION_H
#define __IDENTIFIER_EXPRESSION_H

#include "identifier.h"
#include "expression.h"

class IdentifierExpression : public Expression {
public:
  explicit IdentifierExpression(Identifier& ident);
  void accept(ASTNodeVisitor &v);
  Expression_Type getType();
  std::string getLocation();
private:
  Identifier _ident;
};

#endif // __IDENTIFIER_EXPRESSION_H
