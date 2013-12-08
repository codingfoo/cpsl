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
  Symbol_Metadata metadata1 = SymbolMetadataInitilizer;
  metadata1.type = CPSL_INTEGER;
  addType("integer", metadata1 );

  Symbol_Metadata metadata2 = SymbolMetadataInitilizer;
  metadata2.type = CPSL_CHAR;
  addType("char", metadata2 );

  Symbol_Metadata metadata3 = SymbolMetadataInitilizer;
  metadata3.type = CPSL_BOOLEAN;
  addType("boolean", metadata3 );

  // false -> constant
  // true -> constant
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

void Symbol_Table::addType(std::string symbol, Symbol_Metadata metadata)
{
  _type_symbol_table[symbol] = metadata;
}

Symbol_Map& Symbol_Table::getSymbolTable()
{
  return _global_symbol_table;
}

void Symbol_Table::setVerbose()
{
  _verbose=true;
}
