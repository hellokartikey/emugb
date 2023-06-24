#include <iostream>

#include "cpu/cpu.hxx"
#include "cpu/bus.hxx"
#include "cpu/memory.hxx"

int main() {
    std::cout << "Hello World!\n";

    gb::Bus bus;
    gb::Memory memory(bus);
    gb::CPU cpu(bus, memory);

    /** start - inline program */
    // gb::memory_t program = {
    //     gb::LD_D_D8, 0x0A,
    //     gb::HALT
    // };
    // memory.load_memory(program);
    /** end - inline program */

    cpu.execute();

    cpu.print_status();

    return 0;
}
