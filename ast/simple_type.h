#ifndef __SIMPLE_TYPE_H
#define __SIMPLE_TYPE_H

#include <string>
#include "type.h"
#include "identifier.h"

class SimpleType : public Type {
public:
  explicit SimpleType(std::string ident) : _ident(ident) {}
  std::string getValue();
  void setIdent(std::string identifier);
private:
  std::string _ident;
};

#endif // __SIMPLE_TYPE_H
