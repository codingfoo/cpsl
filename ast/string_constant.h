#ifndef __STRING_CONSTANT_H
#define __STRING_CONSTANT_H

#include <iostream>

#include "constant.h"

class StringConstant : public Constant {
public:
  explicit StringConstant(std::string value) : _value(value) {}
  void accept(ASTNodeVisitor &v);
  Expression_Type getType();
  std::string getValue();
  friend std::ostream& operator<< (std::ostream &out, const StringConstant &obj);
private:
  std::string _value;
};

#endif // __STRING_CONSTANT_H
