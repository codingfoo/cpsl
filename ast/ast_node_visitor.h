#ifndef __AST_NODE_VISITOR
#define __AST_NODE_VISITOR

class Program;
class IntegerConstant;
class WriteStatement;
class CharConstant;
class StringConstant;
class Identifier;
class StopStatement;
class Statement;
class StatementList;

class ASTNodeVisitor
{
public:
  virtual void visit( Program & ast_node ) = 0;
  virtual void visit( IntegerConstant &ast_node ) = 0;
  virtual void visit( WriteStatement &ast_node ) = 0;
  virtual void visit( CharConstant &ast_node ) = 0;
  virtual void visit( StringConstant &ast_node ) = 0;
  virtual void visit( Identifier &ast_node ) = 0;
  virtual void visit( StopStatement &ast_node ) = 0;
  virtual void visit( Statement &ast_node ) = 0;
  virtual void visit( StatementList &ast_node ) = 0;
};

#endif //__AST_NODE_VISITOR
