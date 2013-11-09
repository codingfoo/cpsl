#ifndef __STATEMENT_H
#define __STATEMENT_H

#include "ast_node.h"

class Statement : public ASTNode {
public:
  explicit Statement();
  void accept(ASTNodeVisitor &v);
};

#endif // __STATEMENT_H
