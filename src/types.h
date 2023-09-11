#ifndef EMUGB_TYPES_H
#define EMUGB_TYPES_H

#include <cstdint>
#include <functional>
#include <map>
#include <vector>

namespace gbc {
using byte = std::uint8_t;
using word = std::uint16_t;

struct registers_t {  // clang-format off
  // AF = [A F]
  // F = [z n h c x x x x]
  union {
    word AF;
    struct { 
      struct { byte: 4; byte c: 1; byte h: 1; byte n: 1; byte z: 1; };
      byte A;
    };
  };

  // BC = [B C]
  union { word BC; struct { byte C; byte B; }; };

  // DE = [D E]
  union { word DE; struct { byte E; byte D; }; };

  // HL = [H L]
  union { word HL; struct { byte L; byte H; }; };

  // Stack Pointer
  word SP;

  // Program Counter
  word PC;

};  // clang-format on

using cycles_t = std::uint64_t;

template <std::size_t size>
using block = std::array<byte, size>;

using program = std::vector<byte>;

using opcode_t = std::function<void()>;
using table_t = std::map<byte, opcode_t>;
}  // namespace gbc

#endif