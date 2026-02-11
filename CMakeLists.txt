cmake_minimum_required(VERSION 3.10)
project(String C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Library

add_library(String src/String.c)
target_include_directories(String PUBLIC include)
target_compile_options(String PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)

# Testing

add_subdirectory(extern/unity)

enable_testing()

# Test executables

add_executable(Test__String_equals test/Test__String_equals.c)
target_link_libraries(Test__String_equals PRIVATE String unity)
add_test(NAME Test:String__equals COMMAND Test__String_equals)
