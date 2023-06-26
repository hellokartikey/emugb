#include <iostream>

#include "cpu.hxx"
#include "bus.hxx"
#include "memory.hxx"

using namespace gb;

int main() {
    std::cout << "Hello World!\n";

    Bus bus;
    Memory memory(bus);
    CPU cpu(bus, memory);

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
