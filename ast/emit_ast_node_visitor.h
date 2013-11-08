#ifndef __EMIT_AST_NODE_VISITOR
#define __EMIT_AST_NODE_VISITOR

#include "ast_node_visitor.h"

class EmitASTNodeVisitor : public ASTNodeVisitor
{
public:
  explicit EmitASTNodeVisitor();
  virtual void visit( Program & ast_node );
  virtual void visit( StatementList & ast_node );
  virtual void visit( IntegerConstant & ast_node );
  virtual void visit( WriteStatement & ast_node );
  virtual void visit( CharConstant & ast_node );
  virtual void visit( StringConstant & ast_node );
  virtual void visit( Identifier & ast_node );
  virtual void visit( StopStatement & ast_node );
  virtual void visit( Statement & ast_node );
};

#endif //__EMIT_AST_NODE_VISITOR
