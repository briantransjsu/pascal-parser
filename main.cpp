#include <iostream>

#include "parser.h"
#include "symtab.h"
using std::cout, std::endl;
#include "scanner.h"

int main(int argc, char *argv[]) {
  std::string input = "x := 5; y := 10;";
  int position = 0;
  cmpe125_scanner::Token token = cmpe125_scanner::getNextToken(input, position);
  while (token.type != cmpe125_scanner::END_OF_FILE) {
    if (token.type == cmpe125_scanner::IDENTIFIER &&
        cmpe125_scanner::getNextToken(input, position).value == ":=") {
      cmpe125_scanner::Token nextToken =
          cmpe125_scanner::getNextToken(input, position);
      if (nextToken.type == cmpe125_scanner::NUMBER) {
        cout << "Assigning " << nextToken.value << " to variable "
             << token.value << endl;
      }
    }
    token = cmpe125_scanner::getNextToken(input, position);
  }
}
