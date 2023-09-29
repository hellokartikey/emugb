target_sources(
  ${TEST_TARGET}
  PRIVATE bus.cc
  PRIVATE memory.cc

  # Row 0
  PRIVATE nop.cc
  PRIVATE ld_bc_d16.cc
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
