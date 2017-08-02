add_executable(print_test print_test.cpp)
target_include_directories(print_test PRIVATE "${CMAKE_SOURCE_DIR}")

add_test(NAME TestPrint COMMAND "${CMAKE_CURRENT_BINARY_DIR}/print_test")
