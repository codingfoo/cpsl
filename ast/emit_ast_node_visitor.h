#ifndef __EMIT_AST_NODE_VISITOR
#define __EMIT_AST_NODE_VISITOR

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "ast_node_visitor.h"
#include "../symbol_table/cpsl_base_type.h"

class EmitASTNodeVisitor : public ASTNodeVisitor
{
public:
  explicit EmitASTNodeVisitor();
  ~EmitASTNodeVisitor();
  virtual void visit( Program & ast_node );
  virtual void visit( IdentifierList & ast_node );
  virtual void visit( StatementList & ast_node );
  virtual void visit( Statement & ast_node );
  virtual void visit( FunctionCall & ast_node );
  virtual void visit( StopStatement & ast_node );
  virtual void visit( ReadStatement & ast_node );
  virtual void visit( WriteStatement & ast_node );
  virtual void visit( NullStatement & ast_node );
  virtual void visit( IfStatement & ast_node );
  virtual void visit( Function & ast_node );
  virtual void visit( Routine & ast_node );
  virtual void visit( RoutineList & ast_node );
  virtual void visit( ExpressionList & ast_node );
  virtual void visit( Expression & ast_node );
  virtual void visit( IdentifierExpression & ast_node );
  virtual void visit( GTExpression & ast_node );
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
  void emitData(std::string label, Cpsl_Base_Type type, std::string data);
  std::ofstream asmfile;
  int constantCounter;
  int ifCounter;
  std::string currentFunc;
};

#endif //__EMIT_AST_NODE_VISITOR
