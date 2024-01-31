enable_testing()
add_executable(${TEST_TARGET})
include(GoogleTest)
gtest_discover_tests(${TEST_TARGET})

target_sources(
  ${TEST_TARGET}
  PRIVATE registers.cc
)

target_link_libraries(
  ${TEST_TARGET}
  GTest::gtest_main
  fmt::fmt
  gbc
)

target_include_directories(
  ${TEST_TARGET}
  PUBLIC ../src/gbc
)
