add_executable(print_test print_test.cpp)
add_executable(sprint_test sprint_test.cpp)
target_include_directories(print_test PRIVATE "${CMAKE_SOURCE_DIR}/include" "/usr/local/include")
target_include_directories(sprint_test PRIVATE "${CMAKE_SOURCE_DIR}/include" "/usr/local/include")

add_test(NAME TestPrint COMMAND "${CMAKE_CURRENT_BINARY_DIR}/print_test")
add_test(NAME TestSprint COMMAND "${CMAKE_CURRENT_BINARY_DIR}/sprint_test")
