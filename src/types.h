#ifndef EMUGB_TYPES_H
#define EMUGB_TYPES_H

#include <cstdint>
#include <functional>
#include <map>
#include <string>
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
      union {
        byte F;
        struct { byte: 4; byte c: 1; byte h: 1; byte n: 1; byte z: 1; };
      };
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

bool operator==(const registers_t& lhs, const registers_t& rhs);
bool operator!=(const registers_t& lhs, const registers_t& rhs);

bool bit(const byte& r8, const std::size_t bit);
void bit(byte& r8, const std::size_t bit, bool value);

using cycles_t = std::uint64_t;

template <std::size_t size>
using block_t = std::array<byte, size + 1>;

using program_t = std::array<byte, 0x4000>;

using opcode_t = std::function<void()>;
using table_t = std::map<byte, opcode_t>;

using instruction_t = std::string;
using asm_t = std::vector<instruction_t>;
}  // namespace gbc

#endif