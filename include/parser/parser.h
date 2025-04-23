// Copyright - Victor Miguel de Morais Costa
#ifndef KUCHIKI_PARSER_PARSER_H
#define KUCHIKI_PARSER_PARSER_H

#include <vector>

#include "../utils/token.h"

namespace kuchiki {
namespace parser {

class Parser {
public:
  Parser(const std::vector<kuchiki::utils::Token> &tokens);

private:
  const std::vector<kuchiki::utils::Token> tokens_;
};

} // namespace parser

} // namespace kuchiki

#endif