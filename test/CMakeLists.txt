target_sources(
  ${TEST_TARGET}
  PRIVATE fixture.cxx
  PRIVATE bus.cxx
  PRIVATE memory.cxx
  PRIVATE cpu.cxx
  PRIVATE opcode.cxx
  PRIVATE misc.cxx
  PRIVATE ld_r16_d16.cxx
  PRIVATE ld_r8_d8.cxx
  PRIVATE ld_b_r8.cxx
  PRIVATE ld_c_r8.cxx
  PRIVATE ld_d_r8.cxx
  PRIVATE ld_e_r8.cxx
  PRIVATE ld_h_r8.cxx
  PRIVATE ld_l_r8.cxx
  PRIVATE ld_ar16_r8.cxx
  PRIVATE ld_a_r8.cxx
  PRIVATE ld_a_a8.cxx
  PRIVATE push.cxx
  PRIVATE pop.cxx
  PRIVATE inc.cxx
  PRIVATE dec.cxx
  PRIVATE rst.cxx
  PRIVATE rotates.cxx
  PRIVATE jp.cxx
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
