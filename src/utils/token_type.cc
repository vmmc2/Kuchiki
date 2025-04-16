// Copyright - Victor Miguel de Morais Costa

#include "../../include/utils/token_type.h"

namespace kuchiki {
namespace utils {

std::string TokenTypeToString(TokenType type) {
  static const std::array<std::string, 11> strings{
      "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACE", "RIGHT_BRACE",
      "SEMICOLON",  "IDENTIFIER",  "INTEGER",    "INT",
      "RETURN",     "VOID",        "FILE_END"};

  return strings[static_cast<int>(type)];
};

} // namespace utils
} // namespace kuchiki
