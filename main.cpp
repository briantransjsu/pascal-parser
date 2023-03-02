#include <iostream>
#include "symtab.h"
using std::cout, std::endl;

int main(int argc, char *argv[]) {
      SymbolTable symTable;

    // Add some symbols to the table
    symTable.add_symbol("x", "integer", 10);
    symTable.add_symbol("y", "integer", 10);

    // Check if a symbol exists and retrieve its information
    if (symTable.symbol_exists("x")) {
      //unwrap the x value
      if (auto symbol = symTable.get_symbol("x")) {
        cout << "Symbol name: " << symbol -> name << endl;
        cout << "Symbol type: " << symbol -> type << endl;
        cout << "Symbol value: " << symbol -> value << endl;
      }
      //unwrap the y value
      if (auto symbol = symTable.get_symbol("y")) {
        cout << "Symbol name: " << symbol -> name << endl;
        cout << "Symbol type: " << symbol -> type << endl;
        cout << "Symbol value: " << symbol -> value << endl;
      }
      //unknown
      if (auto symbol = symTable.get_symbol("z")) {
        cout << "Symbol name: " << symbol -> name << endl;
        cout << "Symbol type: " << symbol -> type << endl;
        cout << "Symbol value: " << symbol -> value << endl;
      } else {
	std::cout << "No \"z\" found\n";
      }
    }

    return 0;
}
