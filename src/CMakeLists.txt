add_executable(
  ${BUILD_TARGET})

target_sources(
  ${BUILD_TARGET}
  PRIVATE main.cc)

add_subdirectory(gbc)

target_link_libraries(
  ${BUILD_TARGET}
  fmt::fmt
  gbc)
