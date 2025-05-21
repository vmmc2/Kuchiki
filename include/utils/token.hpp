// Copyright - Victor Miguel de Morais Costa
#ifndef KUCHIKI_UTILS_TOKEN_H
#define KUCHIKI_UTILS_TOKEN_H

#include <any>
#include <ostream>
#include <stdexcept>
#include <string>
#include <typeinfo>

#include "../../include/utils/token_type.hpp"

namespace kuchiki {
namespace utils {

class Token {
public:
  Token(int line, int column, TokenType type, std::string lexeme,
        std::any value);
  int line() const;
  int column() const;
  TokenType type() const;
  const std::string &lexeme() const;
  const std::any &value() const;
  friend std::ostream& operator <<(std::ostream& os, const Token& token);

private:
  int line_;
  int column_;
  TokenType type_;
  std::string lexeme_;
  std::any value_;
};

} // namespace utils
} // namespace kuchiki

#endif
