#include "symbol_metadata.h"
#include "symbol_table.h"

std::ostream& operator<< (std::ostream &out, Symbol_Map symbol_map)
{
  for ( auto iter = symbol_map.begin(); iter != symbol_map.end(); ++iter )
  {
    std::cout << iter->first << '\t' << iter->second.symbol << '\n';
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
  std::cout << "symbol table" << std::endl;
  return out;
}

Symbol_Table::Symbol_Table() : _verbose(false)
{
  // Symbol_Map predefined;

  // std::shared_ptr<Symbol> cpsl_int(new Type("integer", _next_offset));
  // incrementOffset();
  // predefined["integer"] = cpsl_int;
  // predefined["INTEGER"] = cpsl_int;

  // std::shared_ptr<Symbol> cpsl_char(new Type("char", _next_offset));
  // incrementOffset();
  // predefined["char"] = cpsl_char;
  // predefined["CHAR"] = cpsl_char;

  // std::shared_ptr<Symbol> cpsl_boolean(new Type("boolean", _next_offset));
  // incrementOffset();
  // predefined["boolean"] = cpsl_boolean;
  // predefined["BOOLEAN"] = cpsl_boolean;

  // std::shared_ptr<Symbol> cpsl_string(new Type("string", _next_offset));
  // incrementOffset();
  // predefined["string"] = cpsl_string;
  // predefined["STRING"] = cpsl_string;

  // std::shared_ptr<Symbol> cpsl_true(new Type("true", _next_offset));
  // incrementOffset();
  // predefined["true"] = cpsl_true;
  // predefined["TRUE"] = cpsl_true;

  // std::shared_ptr<Symbol> cpsl_false(new Type("false", _next_offset));
  // incrementOffset();
  // predefined["false"] = cpsl_false;
  // predefined["FALSE"] = cpsl_false;

  // scoped_symbol_table.push_back(predefined);

  // Symbol_Map global;

  // scoped_symbol_table.push_back(global);
}

void Symbol_Table::addSymbol(std::string symbol, std::string type)
{
  Symbol_Metadata metadata = SymbolMetadataInitilizer;
  metadata.type = CPSL_INTEGER;
  Symbol_Table::getInstance().addSymbol(symbol, metadata );
}

void Symbol_Table::addSymbol(std::string symbol, Symbol_Metadata metadata)
{
  _global_symbol_table[symbol] = metadata;
}

Symbol_Map& Symbol_Table::getSymbolTable()
{
  return _global_symbol_table;
}

void Symbol_Table::setVerbose()
{
  _verbose=true;
}
