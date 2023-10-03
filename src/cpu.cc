#include "cpu.h"

namespace gbc {
CPU::CPU() {
  reset();
  init();
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

void CPU::ld_r16_d16(word& r16) {
  r16 = read16(registers_.PC);
  registers_.PC += 2;
}

void CPU::ld_ar16_r8(word& ar16, byte& r8) { write(ar16, r8); }

void CPU::inc_r16(word& r16) {
  r16++;
  cycle();
}

void CPU::inc_r8(byte& r8) {
  bool before = (r8 & 0x10);
  r8++;
  bool after = (r8 & 0x10);

  registers_.z = (r8 == 0);
  registers_.n = 0;
  registers_.h = before != after;
}
}  // namespace gbc
