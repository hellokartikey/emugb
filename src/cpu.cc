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

void CPU::connect_bus(Bus& bus) { bus_ = &bus; }

bool CPU::is_bus_connected() { return bus_ != nullptr; }

void CPU::inter() {}

byte CPU::read(word addr) {
  cycle();

  return bus_->read(addr);
}

word CPU::read16(word addr) {
  cycle();
  cycle();

  return bus_->read16(addr);
}

void CPU::write(word addr, byte data) {
  cycle();

  bus_->write(addr, data);
}

void CPU::write16(word addr, word data) {
  cycle();
  cycle();

  bus_->write16(addr, data);
}

void CPU::push(word data) {
  // TODO
}

word CPU::pop() {
  // TODO
  return 0x0000;
}

void CPU::fetch() { fetched_ = read(PC++); }

void CPU::cycle() { cycles_++; }

void CPU::ld_r16_d16(word& r16) {
  r16 = read16(PC);
  PC += 2;
}

void CPU::ld_ar16_r8(word& ar16, byte& r8) { write(ar16, r8); }

void CPU::inc_r16(word& r16) {
  r16++;
  cycle();
}

void CPU::inc_r8(byte& r8) {
  bool old_b3 = bit(r8, 3);
  r8++;
  bool new_b3 = bit(r8, 3);

  registers_.z = (r8 == 0);
  registers_.n = 0;
  registers_.h = old_b3 ? old_b3 != new_b3 : 0;
}

void CPU::dec_r8(byte& r8) {
  bool old_b3 = bit(r8, 3);
  r8--;
  bool new_b3 = bit(r8, 3);

  registers_.z = (r8 == 0);
  registers_.n = 1;
  registers_.h = old_b3 ? old_b3 != new_b3 : 0;
}

void CPU::ld_r8_d8(byte& r8) { r8 = read(PC++); }

void CPU::add_hl(word& r16) {
  bool old_b3 = bit(H, 3);
  word old_HL = HL;
  HL += r16;
  bool new_b3 = bit(H, 3);

  registers_.n = 0;
  registers_.h = old_b3 ? old_b3 != new_b3 : 0;
  registers_.c = HL < old_HL;

  cycle();
}

void CPU::ld_a_ar16(word& r16) { A = read(r16); }

void CPU::dec_r16(word& r16) {
  r16--;
  cycle();
}
}  // namespace gbc
