#include <string>
#include <iostream>

#include <typeinfo>
#include "../symbol_table/symbol_metadata.h"
#include "../symbol_table/symbol_table.h"
#include "program.h"
#include "function.h"
#include "function_call.h"
#include "read_statement.h"
#include "write_statement.h"
#include "if_statement.h"
#include "expression_type.h"
#include "integer_constant.h"
#include "string_constant.h"
#include "routine.h"
#include "routine_list.h"
#include "identifier_expression.h"
#include "gt_expression.h"
#include "add_expression.h"
#include "sub_expression.h"
#include "mul_expression.h"
#include "div_expression.h"
#include "ast_node_visitor.h"
#include "emit_ast_node_visitor.h"

EmitASTNodeVisitor::EmitASTNodeVisitor()
{
  asmfile.open("./output.asm", std::ios::trunc);
  constantCounter = 0;
  ifCounter = 0;
  currentFunc = "";
}

EmitASTNodeVisitor::~EmitASTNodeVisitor()
{
  asmfile.close();
}

void EmitASTNodeVisitor::emitHeader(std::string header)
{
  asmfile << '\t' << header << std::endl;
}

void EmitASTNodeVisitor::emitLabel(std::string label)
{
  asmfile << label << std::endl;
}

void EmitASTNodeVisitor::emitCode(std::string code)
{
  asmfile << '\t' << code << std::endl;
}

void EmitASTNodeVisitor::emitData(std::string label, Cpsl_Base_Type type, std::string data)
{
  std::string mips_type = "word";
  if(type == CPSL_STRING)
  {
    mips_type = "asciiz";
  }
  if(type == CPSL_UDT)
  {
    mips_type = "space";
  }
  if(type == CPSL_ARRAY)
  {
    mips_type = "space";
  }
  asmfile << label << ':' << '\t' << '.' << mips_type << '\t' << data << std::endl;
}

void EmitASTNodeVisitor::visit( Program & ast_node )
{
  emitHeader(".text");
  emitHeader(".globl  main");
  emitLabel("main:");

  ast_node.getStatementList().accept(*this);

  emitLabel("main_end:");
  emitCode("li $v0, 10  #Exit syscall");
  emitCode("syscall");

  ast_node.getRoutineList().accept(*this);

  emitHeader(".data");
  std::string label;
  std::string data;
  for (auto it = Symbol_Table::getInstance().getSymbolTable().begin(); it != Symbol_Table::getInstance().getSymbolTable().end(); it++) {
    label = it->second.label != "" ? it->second.label : it->first;
    emitData( label , it->second.type, it->second.value );
  }

  Symbol_Metadata meta;
  for (auto it = ast_node.getVars().begin(); it != ast_node.getVars().end(); it++)
  {
    meta = Symbol_Table::getInstance().getTypeTable()[it->second];
    if(it->second == "integer")
    {
      emitData( it->first, meta.type, "0" );
    }
    else
    {
      emitData( it->first, CPSL_UDT, "200" );
    }
  }
}

void EmitASTNodeVisitor::visit( StatementList & ast_node )
{
  // std::cout << "Size: " << ast_node.getStatementList().size() << std::endl;
  for (auto it = ast_node.getStatementList().begin(); it != ast_node.getStatementList().end(); it++) {
    // std::cout << "ID: " << typeid(*it).name() << std::endl;
    (*it)->accept(*this);
  }
  // std::cout << std::endl;
}


void EmitASTNodeVisitor::visit( IfStatement & ast_node )
{
  ast_node.getExpression().accept(*this);
  emitCode("beq  $zero, $t0, else" + std::to_string(ifCounter));
  ast_node.getStatements().accept(*this);
  emitCode("j end" + std::to_string(ifCounter));
  emitCode("else" + std::to_string(ifCounter) + ":");
  // ast_node.getElseStatementList().accept(*this);
  emitCode("end" + std::to_string(ifCounter) + ":");
  ifCounter++;
}

void EmitASTNodeVisitor::visit( ReadStatement & ast_node )
{
  if( ast_node.getIdentifier().getType() == INTEGER_EXPRESSION )
  {
    emitCode("li  $v0, 5  #Read integer"); // load appropriate system call code into register $v0
    emitCode("syscall"); // make syscall
    emitCode("sw  $v0, " + currentFunc + ast_node.getIdentifier().getValue());
  }
  else
  {
    emitCode("li  $v0, 12  #Read char"); // load appropriate system call code into register $v0
    emitCode("syscall"); // make syscall
    emitCode("sw  $v0, " + currentFunc + ast_node.getIdentifier().getValue());
  }
}

void EmitASTNodeVisitor::visit( WriteStatement & ast_node )
{
  /*
  print_int    1 $a0 = integer to be printed
  print_string 4 $a0 = address of string in memory
  */
  for (auto it = ast_node.getExpressionList().getExpressionList().begin(); it != ast_node.getExpressionList().getExpressionList().end(); it++) {
    (*it)->accept(*this);

    if( (*it)->getType() == INTEGER_EXPRESSION )
    {
      emitCode("li  $v0, 1  #Write integer"); // load appropriate system call code into register $v0
      emitCode("move  $a0, $t0"); // set up register corresponding to sys call
      emitCode("syscall"); // make syscall
    }

    if( (*it)->getType() == STRING_EXPRESSION )
    {
      emitCode("li  $v0, 4 #Write string"); // load appropriate system call code into register $v0
      emitCode("move  $a0, $t0"); // set up register corresponding to sys call
      emitCode("syscall"); // make syscall
    }

    if( (*it)->getType() == IDENTIFIER_EXPRESSION )
    {
      emitCode("li  $v0, 1  #Write integer"); // load appropriate system call code into register $v0
      emitCode("move  $a0, $t0"); // set up register corresponding to sys call
      emitCode("syscall"); // make syscall
    }
  }
}

void EmitASTNodeVisitor::visit( GTExpression & ast_node )
{
  ast_node.getLeft().accept(*this);

  emitCode("move  $t1,$t0");

  ast_node.getRight().accept(*this);

  emitCode("move  $t2,$t0");

  emitCode("slt  $t0,$t2,$t1");
}

void EmitASTNodeVisitor::visit( AddExpression & ast_node )
{
  ast_node.getLeft().accept(*this);

  emitCode("move  $t1,$t0");

  ast_node.getRight().accept(*this);

  emitCode("move  $t2,$t0");

  emitCode("add  $t0,$t1,$t2");
}

void EmitASTNodeVisitor::visit( SubExpression & ast_node )
{
  ast_node.getLeft().accept(*this);

  emitCode("move  $t1,$t0");

  ast_node.getRight().accept(*this);

  emitCode("move  $t2,$t0");

  emitCode("sub  $t0,$t1,$t2");
}

void EmitASTNodeVisitor::visit( MulExpression & ast_node )
{
  ast_node.getLeft().accept(*this);

  emitCode("move  $t1,$t0");

  ast_node.getRight().accept(*this);

  emitCode("move  $t2,$t0");

  emitCode("mul  $t0,$t1,$t2");
}

void EmitASTNodeVisitor::visit( DivExpression & ast_node )
{
  ast_node.getLeft().accept(*this);

  emitCode("move  $t1,$t0");

  ast_node.getRight().accept(*this);

  emitCode("move  $t2,$t0");

  emitCode("div  $t0,$t1,$t2");
}

void EmitASTNodeVisitor::visit( IntegerConstant & ast_node )
{
  if(ast_node.getType() == INTEGER_EXPRESSION)
  {
    emitCode("li  $t0, " + std::to_string(ast_node.getValue()) );
  }
}

void EmitASTNodeVisitor::visit( StringConstant & ast_node )
{
  if(!Symbol_Table::getInstance().getSymbolTable().count(ast_node.getValue()))
  {
    Symbol_Metadata metadata = SymbolMetadataInitilizer;
    metadata.type = CPSL_STRING;
    metadata.label = "constant" + std::to_string(constantCounter);
    metadata.value = ast_node.getValue();
    std::cout << constantCounter << std::endl;
    std::cout << metadata.value << std::endl;
    Symbol_Table::getInstance().addSymbol(ast_node.getValue(), metadata );
    emitCode("la  $t0, " + metadata.label );
    constantCounter++;
  }
}

void EmitASTNodeVisitor::visit( CharConstant & ast_node ) {}

void EmitASTNodeVisitor::visit( Identifier & ast_node )
{
  //std::cout << "Identifier"<< std::endl;
}

void EmitASTNodeVisitor::visit( IdentifierList & ast_node )
{
  //std::cout << "Identifier"<< std::endl;
}

void EmitASTNodeVisitor::visit( StopStatement & ast_node )
{
  emitCode("j main_end  #Stop statement");
}

void EmitASTNodeVisitor::visit( IdentifierExpression & ast_node )
{
  emitCode("lw  $t0, " + ast_node.getLocation());
}

void EmitASTNodeVisitor::visit( Function & ast_node )
{
  currentFunc = ast_node.getName();
  emitLabel(ast_node.getName() + ':');
  ast_node.getStatementList().accept(*this);
  emitCode("jr $ra");

  Symbol_Metadata meta;
  emitHeader(".data");
  for (auto it = ast_node.getVars().begin(); it != ast_node.getVars().end(); it++)
  {
    meta = Symbol_Table::getInstance().getTypeTable()[it->second];
    if(it->second == "integer")
    {
      emitData( ast_node.getName() + it->first, meta.type, "0" );
    }
    else
    {
      emitData( ast_node.getName() + it->first, CPSL_UDT, "4" );
    }
  }
  for (auto it = ast_node.getArgs().begin(); it != ast_node.getArgs().end(); it++)
  {
    meta = Symbol_Table::getInstance().getTypeTable()[it->second];
    if(it->second == "integer")
    {
      emitData( ast_node.getName() + it->first, meta.type, "0" );
    }
    else
    {
      emitData( ast_node.getName() + it->first, CPSL_UDT, "4" );
    }
  }
  emitHeader(".text");
}

void EmitASTNodeVisitor::visit( FunctionCall & ast_node )
{
  // std::cout << ast_node.getName() << std::endl;
  emitCode("jal " + ast_node.getName());
}

void EmitASTNodeVisitor::visit( RoutineList & ast_node )
{
  for (auto it = ast_node.getRoutineList().begin(); it != ast_node.getRoutineList().end(); it++) {
    (*it)->accept(*this);
  }
}

void EmitASTNodeVisitor::visit( NullStatement & ast_node ) { }

void EmitASTNodeVisitor::visit( Statement & ast_node )
{
  std::cerr << "Error: The Statement method should never be called!" << std::endl;
}

void EmitASTNodeVisitor::visit( ExpressionList & ast_node )
{
  std::cerr << "Error: The ExpressionList method should never be called!" << std::endl;
}

void EmitASTNodeVisitor::visit( Expression & ast_node )
{
  std::cerr << "Error: The Expression method should never be called!" << std::endl;
}

void EmitASTNodeVisitor::visit( Routine & ast_node )
{
  std::cerr << "Error: The Routine method should never be called!" << std::endl;
}
