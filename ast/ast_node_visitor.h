#ifndef __AST_NODE_VISITOR
#define __AST_NODE_VISITOR

class Program;
class StatementList;
class Statement;
class StopStatement;
class WriteStatement;
class ExpressionList;
class Expression;
class AddExpression;
class SubExpression;
class MulExpression;
class IntegerConstant;
class CharConstant;
class StringConstant;
class Identifier;


class ASTNodeVisitor
{
public:
  virtual void visit( Program & ast_node ) = 0;
  virtual void visit( StatementList &ast_node ) = 0;
  virtual void visit( Statement &ast_node ) = 0;
  virtual void visit( StopStatement &ast_node ) = 0;
  virtual void visit( WriteStatement &ast_node ) = 0;
  virtual void visit( ExpressionList & ast_node ) = 0;
  virtual void visit( Expression & ast_node ) = 0;
  virtual void visit( AddExpression & ast_node ) = 0;
  virtual void visit( SubExpression & ast_node ) = 0;
  virtual void visit( MulExpression & ast_node ) = 0;
  virtual void visit( IntegerConstant &ast_node ) = 0;
  virtual void visit( CharConstant &ast_node ) = 0;
  virtual void visit( StringConstant &ast_node ) = 0;
  virtual void visit( Identifier &ast_node ) = 0;
};

#endif //__AST_NODE_VISITOR
