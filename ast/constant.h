#ifndef __CONSTANT_H
#define __CONSTANT_H

#include "expression.h"

class Constant : public Expression {
public:
  explicit Constant();
  virtual Expression_Type getType() = 0;
};

#endif // __CONSTANT_H
