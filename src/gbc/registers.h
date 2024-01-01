#ifndef EMUGB_REGISTERS_H
#define EMUGB_REGISTERS_H

#include <fmt/core.h>
#include <fmt/ostream.h>

#include <algorithm>
#include <ostream>

#include "common.h"

namespace gbc {
class R16 {
 public:  // Types and Alias
  class BitAccess {
   public:
    BitAccess(byte& r8, std::size_t idx);

   public:  // Operators
    auto operator=(bool value) -> BitAccess&;
    operator bool() const;
    friend auto operator<<(std::ostream& os, const BitAccess& out)
        -> std::ostream&;

   private:
    byte& r8;
    std::size_t idx;
  };

  using reference = BitAccess;

 public:
  R16() = default;
  R16(word value);
  R16(byte upper, byte lower);
  ~R16() = default;

  // getters
  auto lo() -> byte&;
  auto up() -> byte&;

  auto operator++() -> R16&;    // prefix increment
  auto operator++(int) -> R16;  // postfix increment
  auto operator--() -> R16&;    // prefix decrement
  auto operator--(int) -> R16;  // postfix decrement
  auto operator[](std::size_t idx) const -> bool;
  auto operator[](std::size_t idx) -> reference;
  friend auto operator+(R16 lhs, R16& rhs) -> R16;  // addition operator
  operator word() const;                            // implicit casting

  friend auto operator<<(std::ostream& os, const R16& out) -> std::ostream&;

 private:
  byte upper, lower;
};
}  // namespace gbc

template <>
struct fmt::formatter<gbc::R16> : ostream_formatter {};

template <>
struct fmt::formatter<gbc::R16::BitAccess> : ostream_formatter {};

#endif
