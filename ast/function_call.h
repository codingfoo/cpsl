#ifndef __FUNCTION_CALL_H
#define __FUNCTION_CALL_H

#include <string>

#include "identifier.h"
#include "statement.h"

class FunctionCall : public Statement {
public:
  explicit FunctionCall(Identifier& ident);
  void accept(ASTNodeVisitor &v);
  std::string getName();
private:
  Identifier _ident;
};

#endif // __FUNCTION_CALL_H
