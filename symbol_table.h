#pragma once

#include "symbol.h"

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
