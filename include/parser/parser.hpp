// Copyright - Victor Miguel de Morais Costa
#ifndef KUCHIKI_PARSER_PARSER_H
#define KUCHIKI_PARSER_PARSER_H

#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>

#include "../utils/ast_nodes.hpp"
#include "../utils/token.hpp"

namespace kuchiki {
namespace parser {

class Parser {
public:
  Parser(const std::vector<kuchiki::utils::Token> &tokens);
  void ParseTokens();

private:
  std::shared_ptr<kuchiki::utils::ASTNode> Program();
  std::shared_ptr<kuchiki::utils::FunctionNode> Function();
  std::shared_ptr<kuchiki::utils::ReturnStatementNode> Statement();
  std::shared_ptr<kuchiki::utils::ConstantExpressionNode> Expression();

  kuchiki::utils::Token Advance();
  bool Check(kuchiki::utils::TokenType token_type);
  kuchiki::utils::Token Consume(kuchiki::utils::TokenType token_type,
                                const std::string &parse_error_message);
  bool IsAtEnd();
  kuchiki::utils::Token Peek();
  kuchiki::utils::Token Previous();

  std::size_t current_index_ = 0;
  const std::vector<kuchiki::utils::Token> &tokens_;
};

} // namespace parser

} // namespace kuchiki

#endif
