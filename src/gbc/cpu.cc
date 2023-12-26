#include "cpu.h"

namespace gbc {
CPU::CPU() {}

CPU::~CPU() {}

auto CPU::read_data_from_bus(byte data) -> void { fetch = data; }
}  // namespace gbc
