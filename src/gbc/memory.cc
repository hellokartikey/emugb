#include "memory.h"

namespace gbc {
Memory::Memory() {}

Memory::~Memory() {}

auto Memory::read_addr_from_bus(word addr) -> void {
  write_data_to_bus(memory[addr]);
}

auto Memory::write_data_from_bus(word addr, byte data) -> void {
  memory[addr] = data;
}

auto Memory::operator[](word addr) -> byte& { return memory[addr]; }
}  // namespace gbc
