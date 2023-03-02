#ifndef SYMTAB_H
#define SYMTAB_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <optional>
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
  void add_symbol(std::string name, std::string type, int value = 0) {
    table[name] = Symbol{name, type, value};
  }

  // Method to get a symbol from the table
  std::optional<Symbol> get_symbol(std::string name) {
    if (auto search = this -> table.find(name); search != this -> table.end())
      return search -> second;
    return {};
  }

  // Method to check if a symbol exists in the table
  bool symbol_exists(std::string name) { return (table.find(name) != table.end()); }
};
#endif
