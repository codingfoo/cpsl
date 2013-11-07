#ifndef __NODE_H
#define __NODE_H
#include <stack>
#include <map>
#include <string>
#include <memory>
#include <iostream>
#include <algorithm> // for copy
#include <iterator> // for ostream_iterator
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
};

class WriteStatement : public ASTNode {
public:
  explicit WriteStatement( IntegerConstant & foo) {}
  explicit WriteStatement( ASTNode & foo) {}
  virtual void accept(class ASTNodeVisitor &v) { v.visit(*this); };
};

class IntegerConstant : public ASTNode {
public:
  explicit IntegerConstant(int value) : _value(value) {}
  virtual void accept(class ASTNodeVisitor &v) { v.visit(*this); };
  friend std::ostream& operator<< (std::ostream &out, const IntegerConstant &constant);
  int getValue() { return _value; }
private:
  int _value;
};

#endif //__NODE_H
