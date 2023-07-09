cmake_minimum_required(VERSION 3.13.4)

set(BUILD_TARGET "emugb")
set(TEST_TARGET "testgb")

project(${BUILD_TARGET} VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
  cmake_policy(SET CMP0135 NEW)
endif()

include(cmake/clang-format.cmake)

include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)

include(cmake/fmt.cmake)
include(cmake/sdl2.cmake)
include(cmake/google-test.cmake)

add_executable(${BUILD_TARGET})

enable_testing()
add_executable(${TEST_TARGET})
include(GoogleTest)
gtest_discover_tests(${TEST_TARGET})

add_subdirectory(src)
add_subdirectory(test)
