#ifndef __EMIT_AST_NODE_VISITOR
#define __EMIT_AST_NODE_VISITOR

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "ast_node_visitor.h"

class EmitASTNodeVisitor : public ASTNodeVisitor
{
public:
  explicit EmitASTNodeVisitor();
  ~EmitASTNodeVisitor();
  virtual void visit( Program & ast_node );
  virtual void visit( StatementList & ast_node );
  virtual void visit( Statement & ast_node );
  virtual void visit( StopStatement & ast_node );
  virtual void visit( WriteStatement & ast_node );
  virtual void visit( ExpressionList & ast_node );
  virtual void visit( Expression & ast_node );
  virtual void visit( AddExpression & ast_node );
  virtual void visit( SubExpression & ast_node );
  virtual void visit( MulExpression & ast_node );
  virtual void visit( DivExpression & ast_node );
  virtual void visit( IntegerConstant & ast_node );
  virtual void visit( CharConstant & ast_node );
  virtual void visit( StringConstant & ast_node );
  virtual void visit( Identifier & ast_node );

private:
  void emitHeader(std::string header);
  void emitLabel(std::string label);
  void emitCode(std::string code);
  void emitData(std::string label, std::string type, std::string data);
  std::ofstream asmfile;
};

#endif //__EMIT_AST_NODE_VISITOR
