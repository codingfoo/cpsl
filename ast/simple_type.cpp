#include "simple_type.h"

#include <iostream>

std::string SimpleType::getValue()
{
  return _ident;
}

void SimpleType::setIdent(std::string identifier)
{
  std::cout << "Error: this method should never be called." << std::endl;
}
