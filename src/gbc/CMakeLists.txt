add_library(
  gbc
  opcodes.h
  common.h
  gameboy.h   gameboy.cc
  registers.h registers.cc
  cpu.h       cpu.cc)

target_link_libraries(
  gbc
  fmt::fmt
  hk::signals)
