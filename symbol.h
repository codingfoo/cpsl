#pragma once

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

class Constant : public Symbol {
  using Symbol::Symbol;
};
