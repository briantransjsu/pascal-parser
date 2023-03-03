#include "parser.h"

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
