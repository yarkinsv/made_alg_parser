cmake_minimum_required(VERSION 3.15)
project(made_parser)

set(CMAKE_CXX_STANDARD 17)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/tests DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(made_parser main.cpp parser.cpp lexer.cpp lexer.h)