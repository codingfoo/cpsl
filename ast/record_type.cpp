#include "record_type.h"

#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "../symbol_table/symbol_table.h"
#include "../symbol_table/symbol_metadata.h"

std::string RecordType::getValue()
{
  return "";
}

void RecordType::setIdent(std::string identifier)
{
  Symbol_Metadata metadata = SymbolMetadataInitilizer;
  metadata.type = CPSL_UDT;
  metadata.record_elements.size();
  for (auto it = _record.begin(); it != _record.end(); it++)
  {
    for (auto idents = (*it)->first.begin(); idents != (*it)->first.end(); idents++)
    {
      metadata.record_elements.push_back( std::pair<std::string, std::string>((*idents)->getValue(), (*it)->second) );
    }
  }
  Symbol_Table::getInstance().addType(identifier, metadata );
}
