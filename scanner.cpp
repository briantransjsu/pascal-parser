#include "scanner.h"

Token getNextToken(std::string input, int& position) {
  // Skip any whitespace
  while (isspace(input[position])) {
    position++;
  }

  // Check for end of file
  if ((size_t)position >= input.length()) {
    return {END_OF_FILE, ""};
  }

  // Check for identifiers
  if (isalpha(input[position])) {
    std::string value = "";
    while (isalnum(input[position])) {
      value += input[position];
      position++;
    }
    return {IDENTIFIER, value};
  }

  // Check for numbers
  if (isdigit(input[position])) {
    std::string value = "";
    while (isdigit(input[position])) {
      value += input[position];
      position++;
    }
    return {NUMBER, value};
  }

  // Check for operators
  if (input[position] == ':' && input[position + 1] == '=') {
    position += 2;  // Skip ":="
    return {OPERATOR, ":="};
  }

  // Check for punctuation
  if (ispunct(input[position])) {
    std::string value = "";
    value += input[position];
    position++;
    return {OPERATOR, value};
  }

  // Error case
  return {END_OF_FILE, ""};
}
