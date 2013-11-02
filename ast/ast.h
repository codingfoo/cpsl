#ifndef __NODE_H
#define __NODE_H

#include "ast_node_visitor.h"

class ASTNode {
public:
  explicit ASTNode() {}
  virtual void accept(class ASTNodeVisitor &v) = 0;
};

class Program : public ASTNode {
public:
  explicit Program() {}
  virtual void accept(class ASTNodeVisitor &v) { v.visit(*this); };
private:
  int _value;
};

class IntegerConstant : public ASTNode {
public:
  explicit IntegerConstant(int value) : _value(value) {}
  virtual void accept(class ASTNodeVisitor &v) { v.visit(*this); };
private:
  int _value;
};

#endif //__NODE_H
