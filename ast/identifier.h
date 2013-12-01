#ifndef __IDENTIFIER_H
#define __IDENTIFIER_H

#include <iostream>
#include "ast_node.h"
#include "expression_type.h"

class Identifier : public ASTNode {
public:
  explicit Identifier(std::string value) : _value(value) {}
  void accept(ASTNodeVisitor &v);
  friend std::ostream& operator<< (std::ostream &out, const Identifier &obj);
  Expression_Type getType();
  std::string getValue();
private:
  std::string _value;
};

#endif // __IDENTIFIER_H
