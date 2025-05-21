// Copyright - Victor Miguel de Morais Costa

#include "../../include/utils/file_scanner.hpp"

namespace kuchiki {

namespace utils {

FileScanner::FileScanner(std::string source_file_path)
    : source_file_path_{source_file_path} {}

void FileScanner::Scan() {
  std::filesystem::path path{source_file_path_};
  if (path.extension() != ".c") {
    throw std::runtime_error{"The compiler expected a '.c' file. But received "
                             "a file with the following extension: " +
                             std::string{path.extension()}};
  }

  std::ifstream file{source_file_path_,
                     std::ios::in | std::ios::binary | std::ios::ate};
  if (!file) {
    throw std::runtime_error{
        "The compiler could not open the '.c' passed as input."};
  }

  source_file_content_.resize(file.tellg());
  file.seekg(0, std::ios::beg);
  file.read(source_file_content_.data(), source_file_content_.size());
  file.close();

  return;
}

const std::string &FileScanner::source_file_content() {
  return source_file_content_;
}

} // namespace utils
} // namespace kuchiki
