// Copyright - Victor Miguel de Morais Costa
#ifndef KUCHIKI_UTILS_TOKEN_TYPE_H
#define KUCHIKI_UTILS_TOKEN_TYPE_H

#include <array>
#include <string>

namespace kuchiki {
namespace utils {

enum TokenType {
  // One-Character Token Types
  kLeftParen,
  kRightParen,
  kLeftBrace,
  kRightBrace,
  kSemicolon,

  // Multi-Character Token Types
  kIdentifier,
  kInteger,

  // Keyword Token Types
  kInt,
  kReturn,
  kVoid,

  // File-End Token Type
  kFileEnd
};

std::string TokenTypeToString(TokenType type);

} // namespace utils
} // namespace kuchiki

#endif
