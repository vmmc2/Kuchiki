// Copyright - Victor Miguel de Morais Costa

#include "../../include/lexer/lexer.h"

namespace kuchiki {

namespace lexer {

Lexer::Lexer(std::string source_file_content)
    : source_file_content_{source_file_content} {}

void Lexer::AddToken(kuchiki::utils::TokenType type) {
  std::string lexeme{
      source_file_content_.substr(start_index_, current_index_ - start_index_)};
  tokens_.push_back(kuchiki::utils::Token{current_line_, current_column_, type,
                                          lexeme, nullptr});

  return;
}

void Lexer::AddToken(kuchiki::utils::TokenType type, std::any value){
  return;
}


bool Lexer::IsAlpha(char c){
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_');
}

bool Lexer::IsAlphaNumeric(char c){
  return IsAlpha(c) || IsDigit(c);
}

bool Lexer::IsDigit(char c){
  return (c >= '0' && c <= '9');
}



} // namespace lexer
} // namespace kuchiki