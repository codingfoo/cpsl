#include "ast.h"
#include "ast_node_visitor.h"

Statement::Statement() {}
void Statement::accept(ASTNodeVisitor &v) { v.visit(*this); }

StatementList::StatementList() {}
void StatementList::accept(ASTNodeVisitor &v) { v.visit(*this); }

WriteStatement::WriteStatement(ASTNode&) {}
WriteStatement::WriteStatement() {}
void WriteStatement::accept(ASTNodeVisitor &v) { v.visit(*this); }

StopStatement::StopStatement() {}
void StopStatement::accept(ASTNodeVisitor &v) { v.visit(*this); }

void IntegerConstant::accept(ASTNodeVisitor &v) { v.visit(*this); }

void CharConstant::accept(ASTNodeVisitor &v) { v.visit(*this); }

void StringConstant::accept(ASTNodeVisitor &v) { v.visit(*this); }

void Identifier::accept(ASTNodeVisitor &v) { v.visit(*this); }

//Program::Program(StatementList* &statements) {}
void Program::accept(ASTNodeVisitor &v) { v.visit(*this); }

Constant::Constant() {}

std::ostream& operator<< (std::ostream &out, const IntegerConstant &obj)
{
    out << obj._value;
    return out;
}

std::ostream& operator<< (std::ostream &out, const CharConstant &obj)
{
    out << obj._value;
    return out;
}

std::ostream& operator<< (std::ostream &out, const StringConstant &obj)
{
    out << obj._value;
    return out;
}

std::ostream& operator<< (std::ostream &out, const Identifier &obj)
{
    out << obj._value;
    return out;
}
