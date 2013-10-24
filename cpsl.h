#include <stack>
#include <map>
#include <string>
#include <memory>
#include <iostream>
#include <algorithm> // for copy
#include <iterator> // for ostream_iterator

class Symbol {
public:
  explicit Symbol(std::string name) : _name(name) {}
  friend std::ostream& operator<< (std::ostream &out, Symbol &symbol);
private:
  std::string _name;
  int _offset;
};

class Type : public Symbol {
  using Symbol::Symbol;
};

std::ostream& operator<< (std::ostream &out, Symbol &symbol)
{
    out << symbol._name;
    return out;
}

class Array : public Type {

};

class Record : public Type {

};

class Integer : public Type {
  using Symbol::Symbol;
public:
  int value;
};

class Char : public Type {
public:
  char value;
};

class String : public Type {
public:
  std::string value;
};

class Function : public Type {
};

class Procedure : public Type {
};

class Identifier : public Type {
  using Type::Type;
};

typedef std::map<std::string, std::shared_ptr<Symbol>> Symbol_Table;

std::ostream& operator<< (std::ostream &out, Symbol_Table table)
{
  for ( std::map<std::string, std::shared_ptr<Symbol>>::const_iterator iter = table.begin(); iter != table.end(); ++iter )
  {
    std::cout << iter->first << '\t' << *iter->second << '\n';
  }

  std::cout << std::endl;
  return out;
}

std::vector<Symbol_Table> symbol_tables;

std::ostream& operator<< (std::ostream &out, std::vector<Symbol_Table> table)
{
    std::copy(table.begin(), table.end(), std::ostream_iterator<Symbol_Table>(out, " "));
    return out;
}

