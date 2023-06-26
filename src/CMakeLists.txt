target_sources(
  ${BUILD_TARGET}
  PRIVATE main.cxx
)

target_link_libraries(
  ${BUILD_TARGET}
  PUBLIC cpu
  PUBLIC gbc
)

add_library(
  cpu
  common.cxx
  bus.cxx
  cpu.cxx
  memory.cxx
)

add_library(
  gbc
  joypad.cxx
  screen.cxx
  speaker.cxx
)
