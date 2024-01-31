#include "registers.h"

namespace gbc {
R16::BitAccess::BitAccess(byte& r8, std::size_t idx) : r8(r8), idx(idx) {}

auto R16::BitAccess::operator=(bool value) -> bit& {
  if (value == true) {
    r8 |= (1 << idx);
  } else {
    r8 &= ~(1 << idx);
  }

  return *this;
}

R16::BitAccess::operator bool() const { return bool(r8 & (1 << idx)); }

auto operator<<(std::ostream& os, const R16::BitAccess& out) -> std::ostream& {
  return os << fmt::format("{}", bool(out.r8 & (1 << out.idx)));
}

R16::R16(word value) {
  upper = (value & 0xff00) >> 8;
  lower = (value & 0x00ff);
}

R16::R16(byte upper, byte lower) : upper(upper), lower(lower) {}

auto R16::lo() -> byte& { return lower; }

auto R16::up() -> byte& { return upper; }

auto R16::operator++() -> R16& {
  this->lower++;
  if (this->lower == 0x00) {
    this->upper++;
  }

  return *this;
}

auto R16::operator++(int) -> R16 {
  auto old = *this;
  operator++();
  return old;
}

auto R16::operator--() -> R16& {
  this->lower--;
  if (this->lower == 0xff) {
    this->upper--;
  }

  return *this;
}

auto R16::operator--(int) -> R16 {
  auto old = *this;
  operator--();
  return old;
}

auto R16::operator[](std::size_t idx) const -> bool {
  if (0 <= idx && idx < 8) {
    return bool(lower & (1 << idx));
  } else {
    return bool(upper & (1 << (idx - 8)));
  }

  return false;
}

auto R16::operator[](std::size_t idx) -> BitAccess {
  if (0 <= idx && idx < 8) {
    return BitAccess(lower, idx);
  } else if (8 <= idx && idx < 16) {
    return BitAccess(upper, idx - 8);
  }

  throw std::out_of_range("Register is only 16bits");
}

R16::operator word() const { return (upper << 8) | lower; }

auto operator+(R16 lhs, R16& rhs) -> R16 { return word(lhs) + word(rhs); }

auto operator<<(std::ostream& os, const R16& out) -> std::ostream& {
  return os << fmt::format("{:02x}{:02x}", out.upper, out.lower);
}
}  // namespace gbc
