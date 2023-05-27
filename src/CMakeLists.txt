target_sources(
    ${PROJECT_NAME}
    PRIVATE main.cxx
    PRIVATE common.cxx
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE .
    PRIVATE cpu
    PRIVATE memory
)

add_subdirectory(cpu)
add_subdirectory(memory)
