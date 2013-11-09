#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

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

  void addId(std::string id);
  void addType(std::string id);
  void pushScope();
  void popScope();
  void setVerbose();

private:
  Symbol_Table();
  Symbol_Table(Symbol_Table const&);   // Leave unimplemented
  void operator=(Symbol_Table const&); // Leave unimplemented
  void incrementOffset();

  int _next_offset;
  std::vector<Symbol_Map> scoped_symbol_table;
  bool _verbose;
};

#endif //__SYMBOL_TABLE_H
