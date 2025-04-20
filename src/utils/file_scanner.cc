// Copyright - Victor Miguel de Morais Costa

#include "../../include/utils/file_scanner.h"

namespace kuchiki {

namespace utils {

FileScanner::FileScanner(std::string source_file_path)
    : source_file_path_{source_file_path} {}

void FileScanner::Scan() {}

const std::string &FileScanner::source_file_content() {
  return source_file_content_;
}

} // namespace utils
} // namespace kuchiki
