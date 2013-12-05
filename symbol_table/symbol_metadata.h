#ifndef SYMBOL_METADATA_H
#define SYMBOL_METADATA_H

#include <string>
#include <iostream>

#include "cpsl_base_type.h"

struct Symbol_Metadata
{
  std::string symbol;
  Cpsl_Base_Type type;
  std::string label;
  std::string value;
};

const Symbol_Metadata SymbolMetadataInitilizer = {"", CPSL_NULL, "", "0"};

#endif //__SYMBOL_METADATA_H
