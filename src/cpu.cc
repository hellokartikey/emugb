#include "cpu.h"

namespace gbc {
CPU::CPU() {
  init();
  init_opcode();
  bus = nullptr;
}

CPU::CPU(Bus& bus) {
  CPU();
  connect_bus(bus);
}

void CPU::init() {}

void CPU::init_opcode() {
  // Row 0
  opcode_table[NOP] = nop;
  opcode_table[LD_BC_D16] = ld_bc_d16;
}

void CPU::execute(cycles_t steps) {
  cycles_t before = cycles;
  while (steps ? cycles < before + steps : true) {
    fetch();

    opcode_table[fetched]();
  }
}

void CPU::reset() { cycles = 0; }

void CPU::inter() {}

void CPU::connect_bus(Bus& bus) {
  this->bus = &bus;
  bus.connect_cpu(*this);
}

bool CPU::is_bus_connected() { return bus != nullptr; }

byte CPU::read(word addr) {
  cycle();
  return bus->read(addr);
}

word CPU::read16(word addr) { return read(addr) | (read(addr + 1) << 8); }

void CPU::write(word addr, byte data) {
  cycle();
  bus->write(addr, data);
}

void CPU::write16(word addr, word data) {
  byte low, hig;
  low = data & 0x00ff;
  hig = (data >> 8) & 0x00ff;

  write(addr, low);
  write(addr + 1, hig);
}

void CPU::push(word data) {
  // TODO
}

word CPU::pop() {
  // TODO
  return 0x0000;
}

void CPU::fetch() { fetched = read(registers.PC++); }

void CPU::cycle() { cycles++; }
}  // namespace gbc
