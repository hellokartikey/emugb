#ifndef EMUGB_COMMON_H
#define EMUGB_COMMON_H

#include <array>
#include <cstddef>
#include <cstdint>
// #include <iterator>

namespace gbc {
using word = std::uint16_t;
using byte = std::uint8_t;

template <std::size_t size>
using memory_block = std::array<byte, size + 1>;
}  // namespace gbc

#endif
