#ifndef __AST_NODE_VISITOR
#define __AST_NODE_VISITOR

#include "ast.h"

class Program;
class IntegerConstant;

class ASTNodeVisitor
{
public:
  explicit ASTNodeVisitor() {}
  virtual void visit( Program & ast_node ) = 0;
  virtual void visit( IntegerConstant & ast_node ) = 0;
};

#endif //__AST_NODE_VISITOR
