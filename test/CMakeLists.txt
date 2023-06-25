enable_testing()

add_executable(
  ${TEST_TARGET}
)

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
)

target_link_libraries(
  ${TEST_TARGET}
  GTest::gtest_main
  cpu
)

target_include_directories(
  ${TEST_TARGET}
  PUBLIC ../src
)

include(GoogleTest)
gtest_discover_tests(${TEST_TARGET})
