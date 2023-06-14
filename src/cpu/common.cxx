#include "common.hxx"

gb::byte gb::rand_byte() {
    return std::rand() % max_byte;
}

gb::word gb::rand_word() {
    return std::rand() % max_word;
}
