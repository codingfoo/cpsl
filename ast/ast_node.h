#ifndef __ASTNODE_H
#define __ASTNODE_H

class ASTNodeVisitor;

class ASTNode {
public:
  virtual void accept(ASTNodeVisitor &v) = 0;
};

#endif //__ASTNODE_H
