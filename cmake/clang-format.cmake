file(GLOB_RECURSE ALL_SOURCE_FILES src/*.cc src/*.h test/*.cc test/*.h)

add_custom_target(
    clangformat
    ALL
    COMMAND /usr/bin/clang-format
    -i
    ${ALL_SOURCE_FILES}
)
