#ifndef __SYMBOL_TABLE_H
#define __SYMBOL_TABLE_H

#include <stack>
#include <map>
#include <string>
#include <memory>
#include <iostream>
#include <algorithm> // for copy
#include <iterator> // for ostream_iterator

#include "symbol.h"

typedef std::map<std::string, std::shared_ptr<Symbol>> Symbol_Map;

class Symbol_Table
{
public:
  static Symbol_Table& getInstance()
  {
    static Symbol_Table instance;
    return instance;
  }

  friend std::ostream& operator<< (std::ostream &out, Symbol_Table &symbol_table);

  void addSymbol(std::string symbol);

private:
  Symbol_Table();
  Symbol_Table(Symbol_Table const&);   // Leave unimplemented
  void operator=(Symbol_Table const&); // Leave unimplemented

  int _next_offset;
  std::vector<Symbol_Map> scoped_symbol_table;
};

#endif //__SYMBOL_TABLE_H
