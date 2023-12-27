add_library(
  gbc
  opcodes.h
  common.h
  gameboy.h   gameboy.cc
  bus.h       bus.cc
  registers.h registers.cc
  cpu.h       cpu.cc
  memory.h    memory.cc)

target_link_libraries(
  gbc
  fmt::fmt
  hk::signals)
