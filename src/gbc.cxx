#include "gbc.hxx"

#include <fmt/core.h>

#include <chrono>
#include <thread>

namespace gb {
GameBoy::GameBoy()
    : memory(bus), cpu(bus, memory), disassembler(memory.connect_memory()) {}

void GameBoy::run() {
  while (1) {
    fmt::print("\033[2J\033[1;1H");
    memory.print_memory(0x0000, 4);
    cpu.print_status();
    disassembler.disassemble(cpu.get_regs().PC, 10);
    cpu.execute(1);
    std::this_thread::sleep_for(std::chrono::seconds(5));
  }
}

void GameBoy::read_rom(const std::string path) { memory.read_from_file(path); }
}  // namespace gb