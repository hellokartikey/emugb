target_sources(
  ${BUILD_TARGET}
  PRIVATE main.cxx
)

target_link_libraries(
  ${BUILD_TARGET}
  PUBLIC cpu
)

add_subdirectory(cpu)
