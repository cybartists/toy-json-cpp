cmake_minimum_required(VERSION 3.21)
project(toy-json-cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(toy-json-cpp test.cpp JSON_AST_STRUCT.h JSON_PARSER_EXCEPTION.h JSON_COMPILER.cpp JSON_COMPILER.h)
