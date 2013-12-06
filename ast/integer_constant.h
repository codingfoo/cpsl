#ifndef __INTEGER_CONSTANT_H
#define __INTEGER_CONSTANT_H

#include <iostream>
#include "constant.h"

class IntegerConstant : public Constant {
public:
  explicit IntegerConstant(int value) : _value(value) {}
  void accept(ASTNodeVisitor &v);
  Expression_Type getType();
  int getValue();
  std::string getConstantValue();
  friend std::ostream& operator<< (std::ostream &out, const IntegerConstant &obj);
private:
  int _value;
};

#endif // __INTEGER_CONSTANT_H
