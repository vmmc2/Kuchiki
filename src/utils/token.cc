// Copyright - Victor Miguel de Morais Costa

#include "../../include/utils/token.h"

namespace kuchiki {
namespace utils {

Token::Token(int line, int column, TokenType type, std::string lexeme,
             std::any value)
    : line_{line}, column_{column}, type_{type}, lexeme_{lexeme},
      value_{value} {}

int Token::line() { return line_; }

int Token::column() { return column_; }

TokenType Token::type() { return type_; }

const std::string &Token::lexeme() { return lexeme_; }

const std::any &Token::value() { return value_; }

std::ostream& operator<<(std::ostream& os, const Token& token) {
  os << "foo";

  return os;
}

} // namespace utils
} // namespace kuchiki
