#ifndef KUCHIKI_UTILS_AST_NODES_H
#define KUCHIKI_UTILS_AST_NODES_H

#include <any>
#include <memory>
#include <string>

#include "token.hpp"

namespace kuchiki {

namespace utils {

class AstNode;
class ConstantExpressionNode;
class ExpressionNode;
class FunctionNode;
class ProgramNode;
class ReturnStatementNode;
class StatementNode;

class IAstVisitor {
public:
  virtual std::any
  VisitConstantExpressionNode(std::shared_ptr<ConstantExpressionNode> node) = 0;
  virtual std::any
  VisitExpressionNode(std::shared_ptr<ExpressionNode> node) = 0;
  virtual std::any VisitFunctionNode(std::shared_ptr<FunctionNode> node) = 0;
  virtual std::any VisitProgramMnode(std::shared_ptr<ProgramNode> node) = 0;
  virtual std::any
  VisitReturnStatementNode(std::shared_ptr<ReturnStatementNode> node) = 0;
  virtual std::any VisitStatementNode(std::shared_ptr<StatementNode> node) = 0;
};

class AstNode {
public:
  virtual ~AstNode() = default;

  virtual std::any Accept(IAstVisitor &visitor) = 0;
};

class ExpressionNode : public AstNode {
public:
  std::any Accept(IAstVisitor &visitor) override = 0;
};

class FunctionNode : public AstNode,
                     public std::enable_shared_from_this<FunctionNode> {
public:
  FunctionNode(kuchiki::utils::Token function_name,
               std::shared_ptr<StatementNode> body)
      : function_name_{function_name}, body_{body} {}

  std::any Accept(IAstVisitor &visitor) override {
    return visitor.VisitFunctionNode(shared_from_this());
  }

  const kuchiki::utils::Token function_name_;
  const std::shared_ptr<StatementNode> body_;
};

class ProgramNode : public AstNode,
                    public std::enable_shared_from_this<ProgramNode> {
public:
  ProgramNode(std::shared_ptr<FunctionNode> function) : function_{function} {}

  std::any Accept(IAstVisitor &visitor) override {
    return visitor.VisitProgramMnode(shared_from_this());
  }

  const std::shared_ptr<FunctionNode> function_;
};

class StatementNode : public AstNode {
public:
  std::any Accept(IAstVisitor &visitor) override = 0;
};

class ReturnStatementNode
    : public StatementNode,
      public std::enable_shared_from_this<ReturnStatementNode> {
public:
  ReturnStatementNode(kuchiki::utils::Token keyword,
                      std::shared_ptr<ConstantExpressionNode> expr)
      : keyword_{keyword}, expr_{expr} {}

  std::any Accept(IAstVisitor &visitor) override {
    return visitor.VisitReturnStatementNode(shared_from_this());
  }

  kuchiki::utils::Token keyword_;
  std::shared_ptr<ConstantExpressionNode> expr_;
};

class ConstantExpressionNode
    : public ExpressionNode,
      public std::enable_shared_from_this<ConstantExpressionNode> {
public:
  ConstantExpressionNode(std::any value) : value_{value} {}

  std::any Accept(IAstVisitor &visitor) {
    return visitor.VisitConstantExpressionNode(shared_from_this());
  }

  const std::any value_;
};

class AstPrinter : public IAstVisitor {
  std::string Print(std::shared_ptr<AstNode> node) {
    return std::any_cast<std::string>(node->Accept(*this));
  }

  std::any VisitConstantExpressionNode(
      std::shared_ptr<ConstantExpressionNode> node) override {}

  std::any VisitExpressionNode(std::shared_ptr<ExpressionNode> node) override {}

  std::any VisitFunctionNode(std::shared_ptr<FunctionNode> node) override {}

  std::any VisitProgramMnode(std::shared_ptr<ProgramNode> node) override {}

  std::any
  VisitReturnStatementNode(std::shared_ptr<ReturnStatementNode> node) override {
  }

  std::any VisitStatementNode(std::shared_ptr<StatementNode> node) override {}
};

} // namespace utils

} // namespace kuchiki

#endif
