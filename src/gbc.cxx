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

    memory.print_memory(cpu.get_regs().PC & 0xfff0, 5);

    fmt::print("{:-^53}\n", "");

    cpu.print_status();

    fmt::print("{:-^53}\n", "");

    disassembler.disassemble(cpu.get_regs().PC, 10);

    fmt::print("{:-^53}\n", "");

    std::this_thread::sleep_for(5s);
    cpu.execute(1);
  }
}

void GameBoy::read_rom(const std::string path) { memory.read_from_file(path); }

void GameBoy::shell() {
  while (1) {
    fmt::print("{}", shell_prompt);
    std::string command;
    std::cin >> command;
    if (command == "exit") {
      break;
    } else if (command == "run") {
      run();
    } else if (command == "rom") {
      std::string path;
      std::cin >> path;
      read_rom(path);
    } else if (command == "dump") {
      word addr;
      std::cin >> std::hex >> addr;
      memory.print_memory(addr);
    } else if (command == "regs") {
      cpu.print_status();
    } else if (command == "dasm") {
      word addr;
      std::cin >> std::hex >> addr;
      disassembler.disassemble(addr, 5);
    } else {
      fmt::print("Invalid command!\n");
    }
  }
}
}  // namespace gb