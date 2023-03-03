#ifndef SCANNER_H
#define SCANNER_H

#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>

enum TokenType { IDENTIFIER, NUMBER, OPERATOR, END_OF_FILE };

static std::unordered_map<TokenType, std::string> translate{
    {IDENTIFIER, "IDENTIFIER"},
    {NUMBER, "NUMBER"},
    {OPERATOR, "OPERATOR"},
    {END_OF_FILE, "END_OF_FILE "},
};

struct Token {
  TokenType type;
  std::string value;
};

Token getNextToken(std::string input, int& position);

#endif
