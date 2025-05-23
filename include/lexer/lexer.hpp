// Copyright - Victor Miguel de Morais Costa
#ifndef KUCHIKI_LEXER_LEXER_H
#define KUCHIKI_LEXER_LEXER_H

#include <cstddef>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

#include "../../include/utils/token.hpp"

namespace kuchiki {
namespace lexer {

class Lexer {
public:
  Lexer(std::string source_file_content);
  ~Lexer() = default;
  bool found_lexing_error();
  const std::vector<kuchiki::utils::Token> &LexTokens();

private:
  void AddToken(kuchiki::utils::TokenType type, std::any value);
  void AddToken(kuchiki::utils::TokenType type);
  char Advance();
  void Identifier();
  void Integer();
  bool IsAlpha(char c);
  bool IsAlphaNumeric(char c);
  bool IsAtEnd();
  bool IsDigit(char c);
  void LexToken();
  bool Match(char expected);
  void MultiLineComment();
  char Peek(std::size_t offset);
  void SingleLineComment();

  std::size_t start_index_ = 0;
  std::size_t current_index_ = 0;
  int current_line_ = 1;
  int current_column_ = 1;
  bool found_lexing_error_ = false;
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
