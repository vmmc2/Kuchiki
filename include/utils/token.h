// Copyright - Victor Miguel de Morais Costa
#ifndef KUCHIKI_UTILS_TOKEN_H
#define KUCHIKI_UTILS_TOKEN_H

#include <any>
#include <ostream>
#include <string>

#include "../../include/utils/token_type.h"

namespace kuchiki {
namespace utils {

class Token {
public:
  Token(int line, int column, TokenType type, std::string lexeme,
        std::any value);
  int line();
  int column();
  TokenType type();
  const std::string &lexeme();
  const std::any &value();
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
