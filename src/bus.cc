#include "bus.h"

// For populating methods in forward declaration
#include "memory.h"

namespace gbc {
Bus::Bus() {
  cpu_ = nullptr;
  mem_ = nullptr;
}

byte Bus::read(word addr) { return (*mem_)[addr]; }

word Bus::read16(word addr) { return read(addr) | (read(addr + 1) << 8); }

void Bus::write(word addr, byte data) { (*mem_)[addr] = data; }

void Bus::write16(word addr, word data) {
  byte low, hig;
  low = data & 0x00ff;
  hig = (data >> 8) & 0x00ff;

  write(addr, low);
  write(addr + 1, hig);
}

void Bus::connect_memory(Memory& memory) { mem_ = &memory; }

bool Bus::is_mem_connected() { return mem_ != nullptr; }
}  // namespace gbc
