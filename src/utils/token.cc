// Copyright - Victor Miguel de Morais Costa

#include "../../include/utils/token.h"
#include <any>
#include <stdexcept>

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

std::ostream &operator<<(std::ostream &os, const Token &token) {
  os << "[Token] - Line: " << token.line_ << " - Column: " << token.column_
  << " - Type: " << TokenTypeToString(token.type_)
  << " - Lexeme: " << token.lexeme_ << " - Value: ";

  if(token.value_.type() == typeid(int)){
    int val = std::any_cast<int>(token.value_);
    os << val << std::endl;
  }else if(token.value_.type() == typeid(std::string)){
    std::string val = std::any_cast<std::string>(token.value_);
    os << val << std::endl;
  }else if(token.value_.type() == typeid(nullptr)){
    os << "NULL" << std::endl;
  }else{
    throw std::runtime_error{"Error while trying to print token information."};
  }

  return os;
}

} // namespace utils
} // namespace kuchiki
