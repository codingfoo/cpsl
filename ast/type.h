#ifndef __TYPE_H
#define __TYPE_H

#include <string>

class Type {
public:
  explicit Type() {}
  virtual std::string getValue() = 0;
  virtual void setIdent(std::string identifier) = 0;
};

#endif // __TYPE_H
