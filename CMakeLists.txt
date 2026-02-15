cmake_minimum_required(VERSION 3.10)
project(String C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Library

add_subdirectory(extern/List)

add_library(String src/String.c)
target_include_directories(String PUBLIC include)
target_compile_options(String PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)
target_link_libraries(String PUBLIC List)

# Testing

add_subdirectory(extern/unity)

enable_testing()

# Test executables

add_executable(test__String_substring test/String_substring.c)
target_link_libraries(test__String_substring PRIVATE String unity)
add_test(NAME Test:String_substring COMMAND test__String_substring)

add_executable(test__String_trimLeadingWhitespace test/String_trimLeadingWhitespace.c)
target_link_libraries(test__String_trimLeadingWhitespace PRIVATE String unity)
add_test(NAME Test:String_trimLeadingWhitespace COMMAND test__String_trimLeadingWhitespace)

add_executable(test__String_splitByWhitespace test/String_splitByWhitespace.c)
target_link_libraries(test__String_splitByWhitespace PRIVATE String unity)
add_test(NAME Test:String_splitByWhitespace COMMAND test__String_splitByWhitespace)

add_executable(test__String_append test/String_append.c)
target_link_libraries(test__String_append PRIVATE String unity)
add_test(NAME Test:String_append COMMAND test__String_append)

add_executable(test__String_prepend test/String_prepend.c)
target_link_libraries(test__String_prepend PRIVATE String unity)
add_test(NAME Test:String_prepend COMMAND test__String_prepend)

add_executable(test__String_equals test/String_equals.c)
target_link_libraries(test__String_equals PRIVATE String unity)
add_test(NAME Test:String_equals COMMAND test__String_equals)

add_executable(test__String_startsWith test/String_startsWith.c)
target_link_libraries(test__String_startsWith PRIVATE String unity)
add_test(NAME Test:String_startsWith COMMAND test__String_startsWith)

add_executable(test__String_endsWith test/String_endsWith.c)
target_link_libraries(test__String_endsWith PRIVATE String unity)
add_test(NAME Test:String_endsWith COMMAND test__String_endsWith)
