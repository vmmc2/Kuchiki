// Copyright - Victor Miguel de Morais Costa

#include "../../include/lexer/lexer.h"
#include <iostream>
#include <stdexcept>

namespace kuchiki {

namespace lexer {

Lexer::Lexer(std::string source_file_content)
    : source_file_content_{source_file_content} {}

void Lexer::AddToken(kuchiki::utils::TokenType type) {
  AddToken(type, nullptr);

  return;
}

void Lexer::AddToken(kuchiki::utils::TokenType type, std::any value) {
  std::string lexeme{
      source_file_content_.substr(start_index_, current_index_ - start_index_)};
  tokens_.push_back(kuchiki::utils::Token{current_line_, current_column_, type,
                                          lexeme, value});
  current_column_ += (current_index_ - start_index_);
  return;
}

char Lexer::Advance() {
  current_index_ += 1;

  return source_file_content_[current_index_ - 1];
}

bool Lexer::found_lexing_error() { return found_lexing_error_; }

void Lexer::Identifier() {
  while (!IsAtEnd() && IsAlphaNumeric(Peek(0))) {
    Advance();
  }

  if (IsAlphaNumeric(Peek(0))) {
    found_lexing_error_ = true;
    return;
  }

  std::string lexeme =
      source_file_content_.substr(start_index_, current_index_ - start_index_);

  kuchiki::utils::TokenType type = keywords_.find(lexeme) != keywords_.end()
                                       ? keywords_[lexeme]
                                       : kuchiki::utils::TokenType::kIdentifier;

  AddToken(type);
}

void Lexer::Integer() {
  while (!IsAtEnd() && IsDigit(Peek(0))) {
    Advance();
  }
  if (IsAlphaNumeric(Peek(0))) {
    found_lexing_error_ = true;
    return;
  }

  std::any value = std::stoi(
      source_file_content_.substr(start_index_, current_index_ - start_index_));
  AddToken(kuchiki::utils::TokenType::kInt, value);
}

bool Lexer::IsAlpha(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_');
}

bool Lexer::IsAlphaNumeric(char c) { return IsAlpha(c) || IsDigit(c); }

bool Lexer::IsAtEnd() {
  return current_index_ >= source_file_content_.length();
}

bool Lexer::IsDigit(char c) { return (c >= '0' && c <= '9'); }

void Lexer::LexToken() {
  char current_char = Advance();

  switch (current_char) {
  case '(':
    AddToken(kuchiki::utils::TokenType::kLeftParen);
    break;
  case ')':
    AddToken(kuchiki::utils::TokenType::kRightParen);
    break;
  case '{':
    AddToken(kuchiki::utils::TokenType::kLeftBrace);
    break;
  case '}':
    AddToken(kuchiki::utils::TokenType::kRightBrace);
    break;
  case ';':
    AddToken(kuchiki::utils::TokenType::kSemicolon);
    break;
  case '/':
    // Single-Line Comment
    if (Match('/')) {
      SingleLineComment();
      // Multi-Line Comment
    } else if (Match('*')) {
      MultiLineComment();
      // Division Operator
    } else {
    }
    break;
  case '\n':
    current_line_ += 1;
    current_column_ = 1;
    break;
  case ' ':
  case '\r':
  case '\t':
    current_column_ += 1;
    break;
  default:
    // Possible Identifier
    if (IsAlpha(current_char)) {
      Identifier();
    }
    // Possible Integer Constant
    else if (IsDigit(current_char)) {
      Integer();
    } else {
      found_lexing_error_ = true;
    }
    break;
  }
  if (found_lexing_error_) {
    return;
  }
}

const std::vector<kuchiki::utils::Token> &Lexer::LexTokens() {
  while (!IsAtEnd()) {
    start_index_ = current_index_;
    LexToken();
    if (found_lexing_error_) {
      break;
    }
  }
  tokens_.push_back(kuchiki::utils::Token{current_line_, current_column_,
                                          kuchiki::utils::TokenType::kFileEnd,
                                          "", nullptr});
  return tokens_;
}

bool Lexer::Match(char expected) {
  if (IsAtEnd()) {
    return false;
  } else if (source_file_content_[current_index_] != expected) {
    return false;
  } else {
    current_index_ += 1;
    return true;
  }
}

void Lexer::MultiLineComment() {
  while (!IsAtEnd()) {
    std::cout << source_file_content_[current_index_] << std::endl;
    if (Peek(0) == '\n') {
      current_line_ += 1;
    } else if (Peek(0) == '*' && Peek(1) == '/') {
      Advance();
      Advance();
      return;
    } else {
      Advance();
    }
  }

  if (IsAtEnd()) {
    throw std::runtime_error{"Unfinished Multi-Line Comment."};
  }
}

char Lexer::Peek(std::size_t offset) {
  if (IsAtEnd() || current_index_ + offset >= source_file_content_.length()) {
    return '\0';
  } else {
    return source_file_content_[current_index_ + offset];
  }
}

void Lexer::SingleLineComment() {
  while (!IsAtEnd() && Peek(0) != '\n') {
    Advance();
  }
}

} // namespace lexer
} // namespace kuchiki
