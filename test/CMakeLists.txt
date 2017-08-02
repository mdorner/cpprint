cmake_minimum_required(VERSION 3.3)

project(mdorner/print)

add_test(print_test print_test.cpp)
target_include_directories(print_test "${CMAKE_SOURCE_DIR}")
