#ifndef __NODE_H
#define __NODE_H

#include <stack>
#include <map>
#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <algorithm> // for copy
#include <iterator> // for ostream_iterator

class ASTNodeVisitor;

class ASTNode {
public:
  virtual void accept(ASTNodeVisitor &v) = 0;
};

class Statement : public ASTNode {
public:
  explicit Statement();
  void accept(ASTNodeVisitor &v);
};

class StatementList : public ASTNode {
public:
  explicit StatementList();
  void push_back(Statement* statement) { _list.push_back( statement ); }
  void accept(ASTNodeVisitor &v);
  std::vector<Statement*>& getStatementList(){ return _list; }
private:
  std::vector<Statement*> _list;
};

class Program : public ASTNode {
public:
  explicit Program(StatementList* &statements) : _sl(statements) {}
  void accept(ASTNodeVisitor &v);
private:
  StatementList* _sl;
};

class Constant : public ASTNode {
public:
  explicit Constant();
};

class IntegerConstant : public Constant {
public:
  explicit IntegerConstant(int value) : _value(value) {}
  void accept(ASTNodeVisitor &v);
  friend std::ostream& operator<< (std::ostream &out, const IntegerConstant &obj);
private:
  int _value;
};

class WriteStatement : public Statement {
public:
  explicit WriteStatement();
  explicit WriteStatement( IntegerConstant &foo );
  explicit WriteStatement( ASTNode &foo );
  void accept(ASTNodeVisitor &v);
};

class StopStatement : public Statement {
public:
  explicit StopStatement();
  void accept(ASTNodeVisitor &v);
};

class CharConstant : public Constant {
public:
  explicit CharConstant(char value) : _value(value) {}
  void accept(ASTNodeVisitor &v);
  friend std::ostream& operator<< (std::ostream &out, const CharConstant &obj);
private:
  char _value;
};

class StringConstant : public Constant {
public:
  explicit StringConstant(std::string value) : _value(value) {}
  void accept(ASTNodeVisitor &v);
  friend std::ostream& operator<< (std::ostream &out, const StringConstant &obj);
private:
  std::string _value;
};

class Identifier : public ASTNode {
public:
  explicit Identifier(std::string value) : _value(value) {}
  void accept(ASTNodeVisitor &v);
  friend std::ostream& operator<< (std::ostream &out, const Identifier &obj);
private:
  std::string _value;
};

#endif //__NODE_H
