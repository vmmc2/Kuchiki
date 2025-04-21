#include <iostream>
#include <vector>

#include "../include/lexer/lexer.h"
#include "../include/utils/file_scanner.h"
#include "../include/utils/token.h"

int main(int argc, char *argv[]) {
  std::cout << "Hello, World!" << std::endl;
  std::cout << "The value of 'argc' is: " << argc << std::endl;
  std::cout << "The value of argv[1] is: " << argv[1] << std::endl;

  kuchiki::utils::FileScanner file_scanner{argv[1]};
  file_scanner.Scan();

  kuchiki::lexer::Lexer lexer{file_scanner.source_file_content()};

  std::vector<kuchiki::utils::Token> tokens = lexer.LexTokens();

  for (auto &token : tokens) {
    std::cout << token << std::endl;
  }

  return 0;
}
