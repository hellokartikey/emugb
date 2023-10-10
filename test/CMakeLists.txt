target_sources(
  ${TEST_TARGET}
  PRIVATE bus.cc
  PRIVATE memory.cc

  # Row 0
  PRIVATE nop.cc
  PRIVATE ld_bc_d16.cc
  PRIVATE ld_abc_a.cc
  PRIVATE inc_bc.cc
  PRIVATE inc_b.cc
  PRIVATE dec_b.cc
  PRIVATE ld_b_d8.cc
  PRIVATE rlca.cc
  PRIVATE ld_a16_sp.cc
  PRIVATE add_hl_bc.cc
  PRIVATE ld_a_abc.cc
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
