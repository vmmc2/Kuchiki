// Copyright - Victor Miguel de Morais Costa

#include "../../include/parser/parser.hpp"

namespace kuchiki {
namespace parser {

Parser::Parser(const std::vector<kuchiki::utils::Token> &tokens)
    : tokens_{tokens} {}

void Parser::ParseTokens() {
  std::shared_ptr<kuchiki::utils::ASTNode> program_ast;
  try{
    program_ast = Program();
  }catch(const std::runtime_error& e){
    std::cerr << "An error has happenned during the parsing: " << e.what() << std::endl;
  }
}

std::shared_ptr<kuchiki::utils::ASTNode> Parser::Program() {
  std::shared_ptr<utils::FunctionNode> function_declaration_node = Function();
  return std::make_shared<kuchiki::utils::ProgramNode>(
      function_declaration_node);
}

std::shared_ptr<kuchiki::utils::FunctionNode> Parser::Function() {
  Consume(kuchiki::utils::TokenType::kInt, "Expected the keyword 'int'");
  kuchiki::utils::Token function_identifier =
      Consume(kuchiki::utils::TokenType::kIdentifier,
              "Expected the function identifier.");
  Consume(kuchiki::utils::TokenType::kLeftParen,
          "Expected a '(' after the function identifier.");
  Consume(kuchiki::utils::TokenType::kVoid,
          "Expected the keyword 'void' after the '('.");
  Consume(kuchiki::utils::TokenType::kRightParen,
          "Expected a ')' after the 'void' keyword.");
  Consume(kuchiki::utils::TokenType::kLeftBrace,
          "Expected a '{' after the ')'.");
  std::shared_ptr<utils::ReturnStatementNode> return_statement_node =
      Statement();
  Consume(kuchiki::utils::TokenType::kRightBrace,
          "Expected a '}' after the last statement of the function body.");
  return std::make_shared<kuchiki::utils::FunctionNode>(function_identifier,
                                                        return_statement_node);
}

std::shared_ptr<kuchiki::utils::ReturnStatementNode> Parser::Statement() {
  kuchiki::utils::Token return_keyword = Consume(
      kuchiki::utils::TokenType::kReturn, "Expected the 'return' keyword.");
  std::shared_ptr<kuchiki::utils::ConstantExpressionNode> expr = Expression();
  return std::make_shared<kuchiki::utils::ReturnStatementNode>(return_keyword,
                                                               expr);
}

std::shared_ptr<kuchiki::utils::ConstantExpressionNode> Parser::Expression() {
  kuchiki::utils::Token integer_constant_token =
      Consume(kuchiki::utils::TokenType::kIntegerConstant,
              "Expected an integer constant.");
  return std::make_shared<kuchiki::utils::ConstantExpressionNode>(
      integer_constant_token.value());
}

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

kuchiki::utils::Token Parser::Consume(kuchiki::utils::TokenType token_type,
                                      const std::string &parse_error_message) {
  if (Check(token_type)) {
    return Advance();
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
