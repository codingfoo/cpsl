#include "symbol_table.h"

Symbol_Table::Symbol_Table() :  _next_offset(0)
{
  Symbol_Map predefined;

  std::shared_ptr<Symbol> cpsl_int(new Type("integer", _next_offset));
  ++_next_offset;
  predefined["integer"] = cpsl_int;
  predefined["INTEGER"] = cpsl_int;

  std::shared_ptr<Symbol> cpsl_char(new Type("char", _next_offset));
  ++_next_offset;
  predefined["char"] = cpsl_char;
  predefined["CHAR"] = cpsl_char;

  std::shared_ptr<Symbol> cpsl_boolean(new Type("boolean", _next_offset));
  ++_next_offset;
  predefined["boolean"] = cpsl_boolean;
  predefined["BOOLEAN"] = cpsl_boolean;

  std::shared_ptr<Symbol> cpsl_string(new Type("string", _next_offset));
  ++_next_offset;
  predefined["string"] = cpsl_string;
  predefined["STRING"] = cpsl_string;

  std::shared_ptr<Symbol> cpsl_true(new Type("true", _next_offset));
  ++_next_offset;
  predefined["true"] = cpsl_true;
  predefined["TRUE"] = cpsl_true;

  std::shared_ptr<Symbol> cpsl_false(new Type("false", _next_offset));
  ++_next_offset;
  predefined["false"] = cpsl_false;
  predefined["FALSE"] = cpsl_false;

  scoped_symbol_table.push_back(predefined);

  Symbol_Map global;

  scoped_symbol_table.push_back(global);
}

void Symbol_Table::addIdentifier(std::string identifier)
{
  std::shared_ptr<Identifier> ident(new Identifier(identifier, _next_offset));
  ++_next_offset;
  scoped_symbol_table.back()[identifier] = ident;
}

void Symbol_Table::addType(std::string identifier)
{
  std::shared_ptr<Type> ident(new Type(identifier, _next_offset));
  ++_next_offset;
  scoped_symbol_table.back()[identifier] = ident;
}

std::ostream& operator<< (std::ostream &out, Symbol_Map symbol_map)
{
  for ( std::map<std::string, std::shared_ptr<Symbol>>::const_iterator iter = symbol_map.begin(); iter != symbol_map.end(); ++iter )
  {
    std::cout << iter->first << '\t' << *iter->second << '\n';
  }
  return out;
}

std::ostream& operator<< (std::ostream &out, std::vector<Symbol_Map> symbol_map)
{
  std::copy(symbol_map.begin(), symbol_map.end(), std::ostream_iterator<Symbol_Map>(out, " "));
  return out;
}

std::ostream& operator<< (std::ostream &out, Symbol_Table &symbol_table)
{
  std::cout << symbol_table.scoped_symbol_table;
  return out;
}
