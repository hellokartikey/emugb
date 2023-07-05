target_sources(
  ${BUILD_TARGET}
  PRIVATE main.cxx
)

add_library(
  gbc
  common.cxx
  bus.cxx
  cpu.cxx
  memory.cxx
  joypad.cxx
  screen.cxx
  speaker.cxx
)

target_link_libraries(
  ${BUILD_TARGET}
  SDL2::SDL2main
  fmt::fmt
  gbc
)

target_link_libraries(
  gbc
  fmt::fmt
)
