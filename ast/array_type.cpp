#include "array_type.h"

#include <iostream>

#include "../symbol_table/cpsl_base_type.h"
#include "../symbol_table/symbol_table.h"
#include "../symbol_table/symbol_metadata.h"

std::string ArrayType::getValue()
{
  return "";
}

void ArrayType::setIdent(std::string identifier)
{
  Symbol_Metadata metadata = SymbolMetadataInitilizer;
  metadata.type = CPSL_ARRAY;
  Symbol_Table::getInstance().addType(identifier, metadata );
}
