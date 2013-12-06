#ifndef __ROUTINE_H
#define __ROUTINE_H

#include "ast_node.h"

class Routine : public ASTNode {
public:
  explicit Routine();
  virtual void accept(ASTNodeVisitor &v);
};

#endif //__ROUTINE_H
