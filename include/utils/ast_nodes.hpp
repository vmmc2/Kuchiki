#ifndef KUCHIKI_UTILS_AST_NODES_H
#define KUCHIKI_UTILS_AST_NODES_H

#include <any>
#include <memory>

#include "token.hpp"

namespace kuchiki {

namespace utils {

class ASTNode;
class ConstantExpressionNode;
class ExpressionNode;
class FunctionNode;
class ProgramNode;
class ReturnStatementNode;
class StatementNode;

class ASTNode {
public:
  virtual ~ASTNode() = default;

  virtual void Print(int identation = 0) const = 0;
};

class ExpressionNode : public ASTNode {
public:
  void Print(int indentation = 0) const override = 0;
};

class FunctionNode : public ASTNode {
public:
  FunctionNode(kuchiki::utils::Token function_name,
               std::unique_ptr<StatementNode> body);
  void Print(int indentation = 0) const override = 0;

  const kuchiki::utils::Token function_name_;
  const std::unique_ptr<StatementNode> body_;
};

class ProgramNode : public ASTNode {
public:
  ProgramNode(std::unique_ptr<FunctionNode> function);
  void Print(int indentation = 0) const override = 0;

  const std::unique_ptr<FunctionNode> function_;
};

class StatementNode : public ASTNode {
public:
  void Print(int indentation = 0) const override = 0;
};

class ReturnStatementNode : public StatementNode {
public:
  ReturnStatementNode(kuchiki::utils::Token keyword,
                      std::unique_ptr<ConstantExpressionNode> expr);
  void Print(int indentation = 0) const override {}

  kuchiki::utils::Token keyword_;
  std::shared_ptr<ConstantExpressionNode> expr_;
};

class ConstantExpressionNode : public ExpressionNode {
public:
  ConstantExpressionNode(std::any value);
  void Print(int indentation = 0) const override {}

  const std::any value_;
};

} // namespace utils

} // namespace kuchiki

#endif
