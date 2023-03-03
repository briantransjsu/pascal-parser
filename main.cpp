#include <cctype>
#include <iostream>
#include <string>
#include <vector>

#include "parser.h"
#include "scanner.h"
#include "symtab.h"

using namespace std;


int main() {
  string input = "x := 5; y := 10;";
  int position = 0;
  vector<Node *> statements;

  while ((size_t)position < input.length()) {
    Node *statement = parseAssignment(input, position);
    if (statement == nullptr) {
      cout << "Error parsing input" << endl;
      return 1;
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
  return 0;
}
