// Copyright - Victor Miguel de Morais Costa
#ifndef KUCHIKI_UTILS_EXPR_H
#define KUCHIKI_UTILS_EXPR_H

#include <any>
#include <memory>

class ConstantExpr;

class IExprVisitor {
public:
  IExprVisitor() = default;
  ~IExprVisitor() = default;
  virtual std::any VisitConstantExpr(std::shared_ptr<ConstantExpr> expr) = 0;
};

class Expr {
public:
  Expr() = default;
  ~Expr() = default;
  virtual std::any Accept(IExprVisitor &visitor) = 0;
};

class ConstantExpr : public Expr {
public:
  std::any Accept(IExprVisitor &visitor) override;

  std::any value;
};

#endif