#include <iostream>

#include "bus.hxx"
#include "cpu.hxx"
#include "memory.hxx"

int main() {
  gb::Bus bus;
  gb::Memory memory(bus);
  gb::CPU cpu(bus, memory);

  memory.read_from_file("/home/arch/Desktop/gbc_bios.bin");

  cpu.execute();

  cpu.print_status();

  return 0;
}
