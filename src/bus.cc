#include "bus.h"

// For populating methods in forward declaration
#include "memory.h"

namespace gbc {
Bus::Bus() {}

byte Bus::read(word addr) { return (*memory)[addr]; }

void Bus::write(word addr, byte data) { (*memory)[addr] = data; }

void Bus::connect_cpu(CPU& cpu) { this->cpu = &cpu; }

void Bus::connect_memory(Memory& memory) { this->memory = &memory; }
}  // namespace gbc
