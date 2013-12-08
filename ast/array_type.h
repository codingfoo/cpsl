#ifndef __ARRAY_TYPE_H
#define __ARRAY_TYPE_H

#include <string>
#include <utility>

#include "type.h"

class ArrayType : public Type {
public:
  explicit ArrayType(std::pair<int, std::string> & array) : _array(array) {}
  std::string getValue();
  void setIdent(std::string identifier);
private:
  std::pair<int, std::string> _array;
};

#endif // __ARRAY_TYPE_H
