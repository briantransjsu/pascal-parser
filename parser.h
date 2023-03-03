#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include "symtab.h"
#include "scanner.h"


class Node {
 public:
  virtual ~Node() {}
  virtual void print() = 0;
};

class BinaryOperatorNode : public Node {
 public:
  BinaryOperatorNode(Token op, Node *left, Node *right)
      : op(op), left(left), right(right) {}
  virtual void print() {
    std::cout << "(";
    left->print();
    std::cout << " " << op.value << " ";
    right->print();
    std::cout << ")";
  }

 private:
  Token op;
  Node *left;
  Node *right;
};

class NumberNode : public Node {
 public:
  NumberNode(Token token) : value(token.value) {}
  virtual void print() { std::cout << value; }

 private:
  std::string value;
};

class IdentifierNode : public Node {
 public:
  IdentifierNode(Token token) : name(token.value) {}
  virtual void print() { std::cout << name; }

 private:
  std::string name;
};

class AssignmentNode : public Node {
 public:
  AssignmentNode(IdentifierNode *left, Node *right)
      : left(left), right(right) {}
  virtual void print() {
    left->print();
    std::cout << " := ";
    right->print();
    std::cout << ";" << std::endl;
  }

 private:
  IdentifierNode *left;
  Node *right;
};

Node *parseExpression(std::string input, int &position);

Node *parseAssignment(std::string input, int &position);
Node* parseUnaryExpression(std::string input, int& position); 
Node* parsePrimaryExpression(std::string input, int& position);

class Parser {
 private:
  std::string input;
  int position = 0;
  std::vector<Node *> statements;
  SymbolTable symbol_table;

 public:
  Parser(std::string);
  // return the root node of the parse tree
  Node* parseProgram();
  // output tree to stdout
  void outputTree();
};

#endif
