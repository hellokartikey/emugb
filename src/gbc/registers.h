#ifndef EMUGB_REGISTERS_H
#define EMUGB_REGISTERS_H

#include <fmt/core.h>
#include <fmt/ostream.h>

#include <algorithm>
#include <ostream>

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

class R16 {
 public:
  R16() = default;
  ~R16() = default;

  R16(word value) {
    upper = (value & 0xff00) >> 8;
    lower = (value & 0x00ff);
  }

  R16(byte upper, byte lower) : upper(upper), lower(lower) {}

  // getters
  auto lo() -> byte& { return lower; }

  auto up() -> byte& { return upper; }

  // prefix increment
  auto operator++() -> R16& {
    this->lower++;
    if (this->lower == 0x00) {
      this->upper++;
    }

    return *this;
  }

  // postfix increment
  auto operator++(int) -> R16 {
    auto old = *this;
    operator++();
    return old;
  }

  // prefix decrement
  auto operator--() -> R16& {
    this->lower--;
    if (this->lower == 0xff) {
      this->upper--;
    }

    return *this;
  }

  // postfix decrement
  auto operator--(int) -> R16 {
    auto old = *this;
    operator--();
    return old;
  }

  // implicit casting
  operator word() const { return (upper << 8) | lower; }

  // addition operator
  friend auto operator+(R16 lhs, R16& rhs) -> R16 {
    return word(lhs) + word(rhs);
  }

  friend auto operator<<(std::ostream& os, const R16& out) -> std::ostream& {
    return os << fmt::format("{:02x}{:02x}", out.upper, out.lower);
  }

 private:
  byte upper, lower;
};

}  // namespace gbc

template <>
struct fmt::formatter<gbc::R16> : ostream_formatter {};

#endif
