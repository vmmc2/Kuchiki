#ifndef KUCHIKI_UTILS_AST_NODES_H
#define KUCHIKI_UTILS_AST_NODES_H

#include <any>
#include <iostream>
#include <memory>

class ASTNode{
  virtual ~ASTNode() = default;

  virtual void Print(int identation = 0) const = 0;
};

#endif
