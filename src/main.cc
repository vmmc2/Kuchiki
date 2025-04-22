// Copyright - Victor Miguel de Morais Costa

#include <iostream>
#include <vector>

#include "../include/lexer/lexer.h"
#include "../include/utils/file_scanner.h"
#include "../include/utils/token.h"

int main(int argc, char *argv[]) {
  kuchiki::utils::FileScanner file_scanner{argv[2]};
  file_scanner.Scan();

  kuchiki::lexer::Lexer lexer{file_scanner.source_file_content()};

  std::vector<kuchiki::utils::Token> tokens = lexer.LexTokens();
  if(lexer.found_lexing_error()){
    return 1;
  }

  for (auto &token : tokens) {
    std::cout << token << std::endl;
  }

  return 0;
}
