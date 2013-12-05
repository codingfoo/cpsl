#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stack>
#include <map>
#include <string>
#include <memory>
#include <iostream>
#include <algorithm> // for copy
#include <iterator> // for ostream_iterator

#include "symbol_metadata.h"

typedef std::map<std::string, Symbol_Metadata> Symbol_Map;

class Symbol_Table
{
public:
  static Symbol_Table& getInstance()
  {
    static Symbol_Table instance;
    return instance;
  }

  void addSymbol(std::string symbol, std::string type);
  void addSymbol(std::string symbol, Symbol_Metadata metadata);
  void setVerbose();

  Symbol_Map& getSymbolTable();
  friend std::ostream& operator<< (std::ostream &out, Symbol_Table &symbol_table);

private:
  Symbol_Table();
  Symbol_Table(Symbol_Table const&);   // Leave unimplemented
  void operator=(Symbol_Table const&); // Leave unimplemented

  Symbol_Map _global_symbol_table;
  bool _verbose;
};

#endif //__SYMBOL_TABLE_H
