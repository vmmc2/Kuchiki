// Copyright - Victor Miguel de Morais Costa
#ifndef KUCHIKI_UTILS_FILE_SCANNER_H
#define KUCHIKI_UTILS_FILE_SCANNER_H

#include <string>

namespace kuchiki {

namespace utils {

class FileScanner {
public:
  FileScanner(std::string source_file_path);
  void Scan();
  const std::string &source_file_content();

private:
  std::string source_file_path_;
  std::string source_file_content_;
};

} // namespace utils
} // namespace kuchiki

#endif
