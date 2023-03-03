#ifndef SYMTAB_H
#define SYMTAB_H

#include <algorithm>
#include <iostream>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

// Define a structure for storing symbol information
struct Symbol {
  std::string name;  // Symbol name
  std::string type;  // Symbol data type
  int value;         // Symbol value (if applicable)
};

// Define a class for the symbol table
class SymbolTable {
 private:
  std::unordered_map<std::string, Symbol> table;  // Hash table to store symbols

 public:
  // Method to add a symbol to the table
  void add_symbol(std::string name, std::string type, int value = 0); 

  // Method to get a symbol from the table
  std::optional<Symbol> get_symbol(std::string name);

  // Method to check if a symbol exists in the table
  bool symbol_exists(std::string name) {
    return (table.find(name) != table.end());
  }

  // This one is camecased instead of snake to make sure it wasn't from me.
  void outputSymbolTable();
};
#endif
