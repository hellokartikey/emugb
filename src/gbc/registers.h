#ifndef EMUGB_REGISTERS_H
#define EMUGB_REGISTERS_H

#include "common.h"

namespace gbc {
class Registers {
 public:
  auto AF() -> word;
  auto AF(word value) -> void;
  auto BC() -> word;
  auto BC(word value) -> void;
  auto DE() -> word;
  auto DE(word value) -> void;
  auto HL() -> word;
  auto HL(word value) -> void;
  auto SP() -> word;
  auto SP(word value) -> void;
  auto PC() -> word;
  auto PC(word value) -> void;

  auto A() -> byte;
  auto A(byte value) -> void;
  auto B() -> byte;
  auto B(byte value) -> void;
  auto C() -> byte;
  auto C(byte value) -> void;
  auto D() -> byte;
  auto D(byte value) -> void;
  auto E() -> byte;
  auto E(byte value) -> void;
  auto H() -> byte;
  auto H(byte value) -> void;
  auto L() -> byte;
  auto L(byte value) -> void;

  auto z() -> bool;
  auto z(bool value) -> void;
  auto n() -> bool;
  auto n(bool value) -> void;
  auto h() -> bool;
  auto h(bool value) -> void;
  auto c() -> bool;
  auto c(bool value) -> void;

 private:
  auto get_lower_byte(const word& r) -> byte;
  auto set_lower_byte(word& r, byte value) -> void;

  auto get_upper_byte(const word& r) -> byte;
  auto set_upper_byte(word& r, byte value) -> void;

  auto get_index_bit(const word& r, std::uint32_t idx) -> bool;
  auto set_index_bit(word& r, std::uint32_t idx, bool value) -> void;

 private:
  word af, bc, de, hl, sp, pc;
};
}  // namespace gbc

#endif
