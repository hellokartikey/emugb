#include "gameboy.h"

#include <fmt/core.h>

#include <cassert>

namespace gbc {
Gameboy::Gameboy() {
  cpu.write_addr_to_bus.connect([&](word addr) { bus.addr(addr); });
  cpu.write_data_to_bus.connect([&](byte data) { bus.data(data); });

  bus.addr_signal.connect([&](word addr) { bus.data(memory[addr]); });
  bus.data_signal.connect([&](byte data) { memory[bus.addr()] = data; });
  bus.data_signal.connect([&](byte data) { cpu.read_data_from_bus(data); });
}

Gameboy::~Gameboy() {}

auto Gameboy::init() -> void {}

auto Gameboy::test() -> void {
  auto reg = R16{0x1000};

  auto b = word{reg};

  fmt::print("reg = {}\n", b);
}
}  // namespace gbc
