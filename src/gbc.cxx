#include "gbc.hxx"

#include <fmt/core.h>

#include <chrono>
#include <thread>

namespace gb {
GameBoy::GameBoy()
    : memory(bus), cpu(bus, memory), disassembler(memory.connect_memory()) {}

void GameBoy::run() {
  using namespace std::chrono_literals;
  while (1) {
    fmt::print("\033[2J\033[1;1H");
    // std::this_thread::sleep_for(100ms);
    cpu.execute();
    memory.print_memory(cpu.get_regs().PC & 0xfff0, 5);
    fmt::print("{:-^53}\n", "");
    cpu.print_status();
    fmt::print("{:-^53}\n", "");
    disassembler.disassemble(cpu.get_regs().PC, 7);
    fmt::print("{:-^53}\n", "");
    memory.print_memory(0xffa0, 6);
  }
}

void GameBoy::read_rom(const std::string path) { memory.read_from_file(path); }
}  // namespace gb