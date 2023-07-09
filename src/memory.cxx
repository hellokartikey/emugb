#include "memory.hxx"

#include <fmt/core.h>

#include <fstream>

namespace gb {
Memory::Memory(Bus& bus) : bus(bus) { memory = {0}; }

void Memory::read_bus() {
  word addr = bus.read_addr();

  if (bus.read_signal()) {
    bus.write_data(read(addr));
    return;
  }

  byte data = bus.read_data();
  write(addr, data);
}

void Memory::load_memory(memory_t memory) { this->memory = memory; }

memory_t Memory::dump_memory() { return memory; }

memory_t& Memory::connect_memory() { return memory; }

byte Memory::read(word addr) { return memory[addr]; }

void Memory::write(word addr, byte data) {
  memory[addr] = data;

  if (0xE000 <= addr && addr < 0xFE00) {
    memory[addr - 0x2000] = data;
  }
  if (0xC000 <= addr && addr < 0xDE00) {
    memory[addr + 0x2000] = data;
  }
}

void Memory::read_from_file(std::string path) {
  std::ifstream bios_stream;
  bios_stream.open(path);

  if (!bios_stream.is_open()) {
    std::cerr << "Error: failed to open " << path << "\n";
    return;
  }

  word addr = 0x0000;
  for (byte opcode; !bios_stream.eof(); bios_stream >> opcode) {
    memory[addr++] = opcode;
  }
}

void Memory::print_memory(word start, int lines) {
  fmt::print("addr  ");
  for (int i = 0; i <= 0x0f; i++) {
    fmt::print(" {:x} ", i);
  }

  word begin = start & 0xfff0;
  for (word addr = begin; addr < begin + (lines * 0x0010); addr++) {
    if (addr >= 0xffff) {
      break;
    }
    if ((addr & 0x000f) == 0x0000) {
      fmt::print("\n{:04x}  ", addr);
    }

    if (addr >= start) {
      fmt::print("{:02x} ", memory[addr]);
    } else {
      fmt::print("   ");
    }
  }
  fmt::print("\n");
}
}  // namespace gb