target_sources(
  ${BUILD_TARGET}
  PRIVATE main.cc
)

add_library(
  gbc
  bus.h     bus.cc
  cpu.h     cpu.cc
  memory.h  memory.cc
  opcode.h  opcode.cc
  types.h   types.cc
)

target_link_libraries(
  ${BUILD_TARGET}
  fmt::fmt
  gbc
)

target_link_libraries(
  gbc
  fmt::fmt
)
