#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include "symtab.h"

enum class node_type {
  PROGRAM,
  COMPOUND,
  ASSIGN,
  LOOP,
  TEST,
  WRITE,
  WRITELN,
  ADD,
  SUBTRACT,
  MULTIPLY,
  DIVIDE,
  EQ,
  NE,
  LT,
  GT,
  LE,
  GE,
  VARIABLE,
  INTEGER_CONSTANT,
  REAL_CONSTANT,
  STRING_CONSTANT
};

struct node {
  int level;
  node_type type;
  Symbol values;
  node* parent;
  std::vector<node*> children;
};

class Parser {
 private:
  std::string input;

 public:
  Parser(std::string);
  // return the root node of the parse tree
  node* parseProgram();
  // output tree to stdout
  void outputTree(node);
};

#endif
