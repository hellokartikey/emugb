#include "bus.h"

namespace gbc {
Bus::Bus() {
  cpu.init();

  cpu.connect_bus(*this);

  memory.init();
}

byte Bus::read(word addr) { return memory[addr]; }

void Bus::write(word addr, byte data) { memory[addr] = data; }
}  // namespace gbc
