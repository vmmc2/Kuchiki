// Copyright - Victor Miguel de Morais Costa

#include "../../include/parser/parser.h"

namespace kuchiki {
namespace parser {

Parser::Parser(const std::vector<kuchiki::utils::Token> &tokens)
    : tokens_{tokens} {}
} // namespace parser
} // namespace kuchiki