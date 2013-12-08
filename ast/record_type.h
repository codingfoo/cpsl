#ifndef __RECORD_TYPE_H
#define __RECORD_TYPE_H

#include <string>
#include <vector>
#include <utility>

#include "type.h"
#include "identifier.h"

class RecordType : public Type {
public:
  explicit RecordType(std::vector<std::pair<std::vector<Identifier*>, std::string> *> & record) : _record(record) {}
  std::string getValue();
  void setIdent(std::string identifier);
private:
  std::vector<std::pair<std::vector<Identifier*>, std::string> *> _record;
};

#endif // __RECORD_TYPE_H
