#ifndef __FUNCTION_H
#define __FUNCTION_H

#include "routine.h"
#include "identifier.h"

class Function : public Routine {
public:
  explicit Function(Identifier& ident);
  void accept(ASTNodeVisitor &v);
private:
  Identifier _ident;
};

#endif // __FUNCTION_H
