#include "registers.h"

namespace gbc {
auto Registers::AF() -> word { return af; }

auto Registers::AF(word value) -> void { af = value; }

auto Registers::BC() -> word { return bc; }

auto Registers::BC(word value) -> void { bc = value; }

auto Registers::DE() -> word { return de; }

auto Registers::DE(word value) -> void { de = value; }

auto Registers::HL() -> word { return hl; }

auto Registers::HL(word value) -> void { hl = value; }

auto Registers::SP() -> word { return sp; }

auto Registers::SP(word value) -> void { sp = value; }

auto Registers::PC() -> word { return pc; }

auto Registers::PC(word value) -> void { pc = value; }

auto Registers::A() -> byte { return get_upper_byte(af); }

auto Registers::A(byte value) -> void { set_upper_byte(af, value); }

auto Registers::B() -> byte { return get_upper_byte(bc); }

auto Registers::B(byte value) -> void { set_upper_byte(bc, value); }

auto Registers::C() -> byte { return get_lower_byte(bc); }

auto Registers::C(byte value) -> void { set_lower_byte(bc, value); }

auto Registers::D() -> byte { return get_upper_byte(de); }

auto Registers::D(byte value) -> void { set_upper_byte(de, value); }

auto Registers::E() -> byte { return get_lower_byte(de); }

auto Registers::E(byte value) -> void { set_lower_byte(de, value); }

auto Registers::H() -> byte { return get_upper_byte(hl); }

auto Registers::H(byte value) -> void { set_upper_byte(hl, value); }

auto Registers::L() -> byte { return get_lower_byte(hl); }

auto Registers::L(byte value) -> void { set_lower_byte(hl, value); }

auto Registers::z() -> bool { return get_index_bit(af, 7); }

auto Registers::z(bool value) -> void { set_index_bit(af, 7, value); }

auto Registers::n() -> bool { return get_index_bit(af, 6); }

auto Registers::n(bool value) -> void { set_index_bit(af, 6, value); }

auto Registers::h() -> bool { return get_index_bit(af, 5); }

auto Registers::h(bool value) -> void { set_index_bit(af, 5, value); }

auto Registers::c() -> bool { return get_index_bit(af, 4); }

auto Registers::c(bool value) -> void { set_index_bit(af, 4, value); }

auto Registers::get_lower_byte(const word& r) -> byte { return r & 0x00ff; }

auto Registers::set_lower_byte(word& r, byte value) -> void {
  r = (r & 0xff00) | (value);
}

auto Registers::get_upper_byte(const word& r) -> byte {
  return (r & 0xff00) >> 8;
}

auto Registers::set_upper_byte(word& r, byte value) -> void {
  r = (value << 8) | (r & 0x00ff);
}

auto Registers::get_index_bit(const word& r, std::uint32_t idx) -> bool {
  return r & (1 << idx);
}

auto Registers::set_index_bit(word& r, std::uint32_t idx, bool value) -> void {
  if (value) {
    r = r | (1 << idx);
  } else {
    r = r & (0xffff ^ (1 << idx));
  }
}
}  // namespace gbc
