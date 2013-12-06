#ifndef __CONSTANT_H
#define __CONSTANT_H

#include <string>

#include "expression.h"

class Constant : public Expression {
public:
  explicit Constant();
  virtual Expression_Type getType() = 0;
  virtual std::string getConstantValue() = 0;
};

#endif // __CONSTANT_H
