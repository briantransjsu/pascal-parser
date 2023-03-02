#include <iostream>
#include "symtab.h"
using std::cout, std::endl;

int main(int argc, char *argv[]) {
      SymbolTable symTable;

    // Add some symbols to the table
    symTable.add_symbol("x", "integer", 10);
    symTable.add_symbol("z", "boolean");

    // Check if a symbol exists and retrieve its information
    if (symTable.symbol_exists("x")) {
        Symbol symbol = symTable.get_symbol("x");
        cout << "Symbol name: " << symbol.name << endl;
        cout << "Symbol type: " << symbol.type << endl;
        cout << "Symbol value: " << symbol.value << endl;
    }

    return 0;
}
