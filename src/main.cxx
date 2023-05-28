#include <iostream>

#include "cpu/cpu.hxx"
#include "cpu/memory.hxx"

int main() {
    std::cout << "Hello World!\n";

    Memory memory;
    CPU cpu(memory);

    /** start - inline program */
    memory.write(0x0002, LD_D_D8);  // LD C
    memory.write(0x0003, 0x0A);     // 10d
    memory.write(0x0004, HALT);     // HALT
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
