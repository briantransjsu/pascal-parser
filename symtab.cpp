#include "symtab.h"

std::ostream& operator<<(std::ostream& os, const Symbol& symbol) {
  return os << "name: " << symbol.name << " type: " << symbol.type;
}

void SymbolTable::add_symbol(std::string name, std::string type, int value) {
  this->table[name] = Symbol{name, type, value};
}

std::optional<Symbol> SymbolTable::get_symbol(std::string name) {
  if (auto search = this->table.find(name); search != this->table.end())
    return search->second;
  return {};
}

void SymbolTable::outputSymbolTable() {
    for (const auto& [key, value] : this->table)
      std::cout << "{" << key << ": {" << value << "}\n";
}
