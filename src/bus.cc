#include "bus.h"

// For populating methods in forward declaration
#include "memory.h"

namespace gbc {
Bus::Bus() {}

byte Bus::read(word addr) { return (*mem_)[addr]; }

void Bus::write(word addr, byte data) { (*mem_)[addr] = data; }

void Bus::connect_cpu(CPU& cpu) { cpu_ = &cpu; }

void Bus::connect_memory(Memory& memory) { mem_ = &memory; }
}  // namespace gbc
