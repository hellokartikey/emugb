#include <iostream>

#include "cpu.hxx"
#include "bus.hxx"
#include "memory.hxx"

using namespace gb;

int main() {
    Bus bus;
    Memory memory(bus);
    CPU cpu(bus, memory);

    memory.read_from_file("/home/arch/Desktop/gbc_bios.bin");

    cpu.execute();

    cpu.print_status();

    return 0;
}
