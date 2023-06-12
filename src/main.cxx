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
    gb::program program = {
        gb::LD_D_D8, 0x0A,
        gb::HALT
    };
    memory.load_program(program);
    /** end - inline program */

    cpu.execute();
    std::cout << "A: " << int(cpu.A) << "\n";
    std::cout << "B: " << int(cpu.B) << "\n";
    std::cout << "C: " << int(cpu.C) << "\n";
    std::cout << "D: " << int(cpu.D) << "\n";
    std::cout << "E: " << int(cpu.E) << "\n";
    std::cout << "H: " << int(cpu.H) << "\n";
    std::cout << "L: " << int(cpu.L) << "\n";
    std::cout << "t: " << cpu.cycles << "\n";

    return 0;
}
