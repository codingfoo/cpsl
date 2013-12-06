#ifndef __CHAR_CONSTANT_H
#define __CHAR_CONSTANT_H

#include <iostream>

#include "constant.h"

class CharConstant : public Constant {
public:
  explicit CharConstant(char value) : _value(value) {}
  void accept(ASTNodeVisitor &v);
  Expression_Type getType();
  std::string getConstantValue();
  friend std::ostream& operator<< (std::ostream &out, const CharConstant &obj);
private:
  char _value;
};


#endif // __CHAR_CONSTANT_H
