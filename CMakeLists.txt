cmake_minimum_required(VERSION 3.30)

project(Kuchiki)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++20")

set(SOURCE_FILES
    ./src/utils/token_type.cc
    ./src/utils/token.cc
    ./src/utils/file_scanner.cc
    ./src/lexer/lexer.cc
    ./src/main.cc
)

add_executable(Kuchiki ${SOURCE_FILES})