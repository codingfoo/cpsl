#ifndef __EXPRESSION_H
#define __EXPRESSION_H

#include "ast_node.h"
#include "expression_type.h"

class Expression : public ASTNode {
public:
  explicit Expression();
  void accept(ASTNodeVisitor &v);
  virtual Expression_Type getType() = 0;
};

#endif // __EXPRESSION_H
