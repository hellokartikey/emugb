#include "cpu.h"

namespace gbc {
CPU::CPU()
    : A(AF.up()),
      B(BC.up()),
      C(BC.lo()),
      D(DE.up()),
      E(DE.lo()),
      H(HL.up()),
      L(HL.lo()),
      z(AF[7]),
      n(AF[6]),
      h(AF[5]),
      c(AF[4]) {}

CPU::~CPU() {}

auto CPU::read(word addr) -> byte {
  cycle();
  write_addr_to_bus(addr);
  return data_bus;
}

auto CPU::write(word addr, byte data) -> void {
  cycle();
  write_addr_to_bus(addr);
  write_data_to_bus(data);
}

auto CPU::read16(word addr) -> word {}

auto CPU::write16(word addr, word data) -> void {}

auto CPU::cycle() -> void { clocks++; }

auto CPU::fetch() -> byte {
  auto opcode = read(PC);
  PC++;

  return opcode;
}

auto CPU::read_data_from_bus(byte data) -> void { data_bus = data; }
}  // namespace gbc
