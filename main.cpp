#include <cctype>
#include <iostream>
#include <string>
#include <vector>

#include "parser.h"
#include "scanner.h"
#include "symtab.h"

using namespace std;


int main() {
  Parser p("x := 5; y := 10;");
  p.outputTree();
}
