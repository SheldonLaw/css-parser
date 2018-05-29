cmake_minimum_required(VERSION 3.7)
project(css_parser)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/css_parser.h src/css_block.h)
add_executable(css_parser ${SOURCE_FILES})