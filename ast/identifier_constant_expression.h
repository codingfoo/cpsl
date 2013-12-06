#ifndef __IDENTIFIER_CONSTANT_EXPRESSION_H
#define __IDENTIFIER_CONSTANT_EXPRESSION_H

#include <string>

#include "identifier.h"
#include "constant.h"

class IdentifierConstantExpression : public Constant {
public:
  explicit IdentifierConstantExpression(Identifier& ident);
  void accept(ASTNodeVisitor &v);
  Expression_Type getType();
  std::string getConstantValue();
private:
  Identifier _ident;
};

#endif // __IDENTIFIER_CONSTANT_EXPRESSION_H
