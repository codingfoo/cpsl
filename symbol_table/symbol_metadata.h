#ifndef SYMBOL_METADATA_H
#define SYMBOL_METADATA_H

#include <string>
#include <iostream>
#include <map>
#include <vector>

#include "cpsl_base_type.h"

struct Symbol_Metadata
{
  std::string symbol;
  Cpsl_Base_Type type;
  std::string label;
  std::string value;
  int element_size;
  std::vector<std::pair<std::string, std::string>> record_elements; //name : type
};

const Symbol_Metadata SymbolMetadataInitilizer = {"", CPSL_NULL, "", "0", 4};

#endif //__SYMBOL_METADATA_H
