#include "parser.h"
#include "symtab.h"

Node *parseExpression(std::string input, int &position) {
  Token token = getNextToken(input, position);
  if (token.type == IDENTIFIER) {
    return new IdentifierNode(token);
  }
  if (token.type == NUMBER) {
    return new NumberNode(token);
  }
  return nullptr;
}

Node *parseAssignment(std::string input, int &position) {
  IdentifierNode *left =
      dynamic_cast<IdentifierNode *>(parseExpression(input, position));
  if (left == nullptr) {
    return nullptr;
  }
  Token op = getNextToken(input, position);
  if (op.type != OPERATOR || op.value != ":=") {
    return nullptr;
  }
  Node *right = parseExpression(input, position);
  if (right == nullptr) {
    return nullptr;
  }
  Token semicolon = getNextToken(input, position);
  if (semicolon.type != OPERATOR || semicolon.value != ";") {
    return nullptr;
  }
  return new AssignmentNode(left, right);
}

Parser::Parser(std::string input) : input(input){};

// return the root node of the parse tree
Node *parseProgram();

void Parser::outputTree() {
  while ((size_t)this->position < this -> input.length()) {
    Node *statement = parseAssignment(this -> input, this -> position);
    if (statement == nullptr) {
      std::cout << "Error parsing input" << std::endl;
      std::exit(1);
    }
    statements.push_back(statement);

    // Token semicolon = getNextToken(input, position);
    // if (semicolon.type != OPERATOR || semicolon.value != ";") {
    //     cout << "Expected semicolon" << endl;
    //     return 1;
    // }
  }

  // Print out the abstract syntax tree
  for (Node *statement : statements) {
    statement->print();
    delete statement;
  }
}


