#include "cpu.h"

namespace gbc {
CPU::CPU() {
  reset();
  init();
  init_opcode();
  bus_ = nullptr;
}

CPU::CPU(Bus& bus) {
  CPU();
  connect_bus(bus);
}

cycles_t CPU::cycles() { return cycles_; }

registers_t CPU::registers() { return registers_; }

void CPU::registers(registers_t registers) { registers_ = registers; }

void CPU::init() {}

void CPU::reset() { cycles_ = 0; }

void CPU::execute(cycles_t steps) {
  cycles_t before = cycles_;
  while (steps ? cycles_ < before + steps : true) {
    fetch();

    opcode_table_[fetched_]();
  }
}

void CPU::connect_bus(Bus& bus) {
  bus_ = &bus;
  bus.connect_cpu(*this);
}

bool CPU::is_bus_connected() { return bus_ != nullptr; }

void CPU::init_opcode() {
  // Row 0
  opcode_table_[NOP] = nop;
  opcode_table_[LD_BC_D16] = ld_bc_d16;
}

void CPU::inter() {}

byte CPU::read(word addr) {
  cycle();
  return bus_->read(addr);
}

word CPU::read16(word addr) { return read(addr) | (read(addr + 1) << 8); }

void CPU::write(word addr, byte data) {
  cycle();
  bus_->write(addr, data);
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

void CPU::fetch() { fetched_ = read(registers_.PC++); }

void CPU::cycle() { cycles_++; }
}  // namespace gbc
