// Copyright - Victor Miguel de Morais Costa
#ifndef KUCHIKI_PARSER_PARSER_H
#define KUCHIKI_PARSER_PARSER_H

#include <cstddef>
#include <memory>
#include <vector>

#include "../utils/token.hpp"

namespace kuchiki {
namespace parser {

class Parser {
public:
  Parser(const std::vector<kuchiki::utils::Token>& tokens);
  void ParseTokens();

private:
  void Program();
  void Function();
  void Statement();
  void Expression();

  kuchiki::utils::Token Advance();
  bool Check(kuchiki::utils::TokenType token_type);
  void Consume(kuchiki::utils::TokenType token_type, std::string& parse_error_message);
  bool IsAtEnd();
  kuchiki::utils::Token Peek();
  kuchiki::utils::Token Previous();

  std::size_t current_index_ = 0;
  const std::vector<kuchiki::utils::Token> &tokens_;

};

} // namespace parser

} // namespace kuchiki

#endif