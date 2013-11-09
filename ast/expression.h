#ifndef __EXPRESSION_H
#define __EXPRESSION_H

#include "ast_node.h"

class Expression : public ASTNode {
public:
  explicit Expression();
  void accept(ASTNodeVisitor &v);
};

#endif // __EXPRESSION_H
