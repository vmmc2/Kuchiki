// Copyright - Victor Miguel de Morais Costa
#ifndef KUCHIKI_LEXER_LEXER_H
#define KUCHIKI_LEXER_LEXER_H

#include <map>
#include <string>
#include <vector>

#include "../../include/utils/token.h"

namespace kuchiki {
namespace lexer {

class Lexer {
public:
  Lexer(std::string source_file_content);
  const std::vector<kuchiki::utils::Token> &Lex();
  bool IsAlpha(char c);
  bool IsAlphaNumeric(char c);
  bool IsDigit(char c);
  bool IsAtEnd();
  char Peek(int index);

private:
  int start_index_ = 0;
  int current_index_ = 0;
  int current_line_ = 1;
  int current_column_ = 1;
  std::string source_file_content_;
  std::vector<kuchiki::utils::Token> tokens_;
  std::map<std::string, kuchiki::utils::TokenType> keywords_ = {
      {"int", kuchiki::utils::TokenType::kInt},
      {"return", kuchiki::utils::TokenType::kReturn},
      {"void", kuchiki::utils::TokenType::kVoid},
  };
};

} // namespace lexer

} // namespace kuchiki

#endif