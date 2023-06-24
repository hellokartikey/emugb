enable_testing()

add_executable(
  ${TEST_TARGET}
)

target_sources(
  ${TEST_TARGET}
  PRIVATE fixture.cxx
  PRIVATE bus.cxx
  PRIVATE memory.cxx
  # PRIVATE cpu.cxx
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
