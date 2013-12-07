#ifndef __IDENTIFIER_LIST_H
#define __IDENTIFIER_LIST_H

#include <vector>

#include "identifier.h"

class IdentifierList : public ASTNode {
public:
  explicit IdentifierList();
  void push_back(Identifier* identifier);
  void accept(ASTNodeVisitor &v);
  std::vector<Identifier*>& getIdentifierList();
private:
  std::vector<Identifier*> _list;
};

#endif // __IDENTIFIER_LIST_H
