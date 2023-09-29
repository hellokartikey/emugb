target_sources(
  ${TEST_TARGET}
  PRIVATE bus.cc
  PRIVATE memory.cc
  PRIVATE nop.cc
)

target_link_libraries(
  ${TEST_TARGET}
  GTest::gtest_main
  fmt::fmt
  gbc
)

target_include_directories(
  ${TEST_TARGET}
  PUBLIC ../src
)
