// Copyright - Victor Miguel de Morais Costa
#ifndef KUCHIKI_PARSER_PARSER_H
#define KUCHIKI_PARSER_PARSER_H

#include <cstddef>
#include <memory>
#include <vector>

#include "../utils/token.h"

namespace kuchiki {
namespace parser {

class Parser {
public:
  Parser(const std::vector<kuchiki::utils::Token> &tokens);
  void ParseTokens();

private:
  void Program();
  void FunctionDeclStatement();
  void Statement();
  void Expression();

  std::size_t current_index_ = 0;
  const std::vector<kuchiki::utils::Token> &tokens_;

};

} // namespace parser

} // namespace kuchiki

#endif