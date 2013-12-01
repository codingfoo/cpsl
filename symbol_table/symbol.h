#ifndef __SYMBOL_H
#define __SYMBOL_H

#include <stack>
#include <map>
#include <string>
#include <memory>
#include <iostream>
#include <algorithm> // for copy
#include <iterator> // for ostream_iterator

#include "cpsl_base_type.h"

class Symbol {
public:
  explicit Symbol(std::string name, Cpsl_Base_Type type, int offset) : _name(name), _offset(offset) {}
  friend std::ostream& operator<< (std::ostream &out, Symbol &symbol);
private:
  std::string _name;
  int _offset;
};

// class Type : public Symbol {
//   using Symbol::Symbol;
// };

// class Array : public Type {

// };

// class Record : public Type {

// };

// class Integer : public Type {
//   using Symbol::Symbol;
// public:
//   int value;
// };

// class Char : public Type {
// public:
//   char value;
// };

// class String : public Type {
// public:
//   std::string value;
// };

// class Function : public Type {
// };

// class Procedure : public Type {
// };

// class Id : public Type {
//   using Type::Type;
// };

#endif //__SYMBOL_H
