// Copyright - Victor Miguel de Morais Costa

#include "../../include/parser/parser.h"

namespace kuchiki {
namespace parser {

Parser::Parser(const std::vector<kuchiki::utils::Token> &tokens)
    : tokens_{tokens} {}

void Parser::ParseTokens() {}

void Parser::Program() {}

void Parser::Function() {}

void Parser::Statement() {}

void Parser::Expression() {}

kuchiki::utils::Token Parser::Advance() {
  if (!IsAtEnd()) {
    current_index_++;
  }
  
  return Previous();
}

bool Parser::Check(kuchiki::utils::TokenType token_type) {
  if (IsAtEnd()) {
    return false;
  }

  return tokens_[current_index_].type() == token_type;
}

void Parser::Consume(kuchiki::utils::TokenType token_type,
                     std::string &parse_error_message) {
  if (Check(token_type)) {
    Advance();
  }

  throw std::runtime_error{parse_error_message};
}

bool Parser::IsAtEnd() {
  return Peek().type() == kuchiki::utils::TokenType::kFileEnd;
}

kuchiki::utils::Token Parser::Peek() { return tokens_[current_index_]; }

kuchiki::utils::Token Parser::Previous() { return tokens_[current_index_ - 1]; }

} // namespace parser

} // namespace kuchiki