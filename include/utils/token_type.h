// Copyright - Victor Miguel de Morais Costa

#include <array>
#include <string>

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
