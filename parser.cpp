#include "parser.h"
#include "scanner.h"
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

Node *parseAssignment(std::string input, int &position, SymbolTable &symbol_table) {
  IdentifierNode *left =
      dynamic_cast<IdentifierNode *>(parseExpression(input, position));
  if (left == nullptr) {
    return nullptr;
  }

  if (!symbol_table.symbol_exists(left -> get_name())) {
    symbol_table.add_symbol(left -> get_name(), "integer");
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
    Node *statement = parseAssignment(this -> input, this -> position, this -> symbol_table);
    if (statement == nullptr) {
      std::cout << "Error parsing input" << std::endl;
      std::exit(1);
    }
    statements.push_back(statement);
  }

  // Print out the abstract syntax tree
  for (Node *statement : statements) {
    statement->print();
    delete statement;
  }

  this -> symbol_table.outputSymbolTable();
}

Node* parseUnaryExpression(std::string input, int& position) {
    Token op = getNextToken(input, position);
    if (op.type == OPERATOR && (op.value == "+" || op.value == "-")) {
        Node* operand = parsePrimaryExpression(input, position);
        if (operand == nullptr) {
            return nullptr;
        }
        return new UnaryOperatorNode(op.value, operand);
    }
    // If there is no unary operator, parse a primary expression instead
    position--;
    return parsePrimaryExpression(input, position);
}

Node* parsePrimaryExpression(std::string input, int& position) {
    Token nextToken = getNextToken(input, position);
    if (nextToken.type == IDENTIFIER) {
        return new IdentifierNode(nextToken);
    } else if (nextToken.type == NUMBER) {
        return new NumberNode(nextToken);
    } else if (nextToken.type == OPERATOR && (nextToken.value == "+" || nextToken.value == "-")) {
        Node* operand = parseUnaryExpression(input, position);
        if (operand == nullptr) {
            return nullptr;
        }
        return new UnaryOperatorNode(nextToken.value, operand);
    } else if (nextToken.type == OPERATOR && nextToken.value == "(") {
        Node* expression = parseExpression(input, position);
        if (expression == nullptr) {
            return nullptr;
        }
        Token closingParen = getNextToken(input, position);
        if (closingParen.type != OPERATOR || closingParen.value != ")") {
            return nullptr;
        }
        return expression;
    }
    return nullptr;
}
