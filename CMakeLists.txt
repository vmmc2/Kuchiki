cmake_minimum_required(VERSION 3.30)

project(Kuchiki)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++20")

set(SOURCE_FILES
    ./src/utils/token_type.cpp
    ./src/utils/token.cpp
    ./src/utils/file_scanner.cpp
    ./src/lexer/lexer.cpp
    ./src/parser/parser.cpp
    ./src/main.cpp
)

add_executable(Kuchiki ${SOURCE_FILES})