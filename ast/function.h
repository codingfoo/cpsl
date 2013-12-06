#ifndef __FUNCTION_H
#define __FUNCTION_H

#include <string>

#include "routine.h"
#include "identifier.h"

class Function : public Routine {
public:
  explicit Function(Identifier& ident);
  void accept(ASTNodeVisitor &v);
  std::string getName();
private:
  Identifier _ident;
};

#endif // __FUNCTION_H
