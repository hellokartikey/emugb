#include "cpu.h"

namespace gbc {
CPU::CPU() {
  init();
  bus = nullptr;
}

CPU::CPU(Bus& bus) {
  init();
  connect_bus(bus);
}

CPU::CPU(Bus* bus) {
  init();
  connect_bus(bus);
}

void CPU::init() {
  opcode_table[NOP] = [this]() { fmt::print("NOP\n"); };
}

void CPU::execute(cycles_t steps) {}

void CPU::reset() {}

void CPU::inter() {}

void CPU::connect_bus(Bus& bus) { this->bus = &bus; }

void CPU::connect_bus(Bus* bus) { this->bus = bus; }

bool CPU::is_bus_connected() { return bus != nullptr; }
}  // namespace gbc
