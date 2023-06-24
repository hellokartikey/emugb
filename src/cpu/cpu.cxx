#include "cpu.hxx"

gb::CPU::CPU(Bus& bus, Memory& memory) : bus(bus), memory(memory) {
    reset();
    init();
}

gb::registers_t gb::CPU::get_regs() {
    return regs;
}

void gb::CPU::set_regs(gb::registers_t regs) {
    this->regs = regs;
}

void gb::CPU::print_status() {
    std::cout << std::hex;
    std::cout << "A: " << int(regs.A) << "\t";
    std::cout << "F: " << int(regs.F) << "\t";
    std::cout << "z n h c" << "\n";

    std::cout << "B: " << int(regs.B) << "\t";
    std::cout << "C: " << int(regs.C) << "\t";
    std::cout << bool(regs.z) << " ";
    std::cout << bool(regs.n) << " ";
    std::cout << bool(regs.h) << " ";
    std::cout << bool(regs.c) << "\n";

    std::cout << "D: " << int(regs.D) << "\t";
    std::cout << "E: " << int(regs.E) << "\n";

    std::cout << "H: " << int(regs.H) << "\t";
    std::cout << "L: " << int(regs.L) << std::endl;
    std::cout << std::dec;

    std::cout << std::endl;

    std::cout << "cycles:\t" << cycles << "\n";
    std::cout << "current:\t" << current << "\n";
}

gb::cycles_t gb::CPU::get_cycles() {
    return cycles;
}

gb::byte gb::CPU::get_current() {
    return current;
}

void gb::CPU::reset() {
    regs.AF = 0;
    regs.BC = 0;
    regs.DE = 0;
    regs.HL = 0;
    regs.SP = 0;
    regs.PC = 0;
    current = 0;
    cycles = 0;
}

void gb::CPU::init() {
    regs.PC = 0x0100;
    regs.AF = 0x11B0;
    regs.BC = 0x0013;
    regs.DE = 0x00D8;
    regs.HL = 0x014D;
    regs.SP = 0xFFFE;

    gb::memory_t init_memory;
    init_memory[0xFF05] = 0x00;
    init_memory[0xFF06] = 0x00;
    init_memory[0xFF07] = 0x00;
    init_memory[0xFF10] = 0x80;
    init_memory[0xFF11] = 0xBF;
    init_memory[0xFF12] = 0xF3;
    init_memory[0xFF14] = 0xBF;
    init_memory[0xFF16] = 0x3F;
    init_memory[0xFF17] = 0x00;
    init_memory[0xFF19] = 0xBF;
    init_memory[0xFF1A] = 0x7F;
    init_memory[0xFF1B] = 0xFF;
    init_memory[0xFF1C] = 0x9F;
    init_memory[0xFF1E] = 0xBF;
    init_memory[0xFF20] = 0xFF;
    init_memory[0xFF21] = 0x00;
    init_memory[0xFF22] = 0x00;
    init_memory[0xFF23] = 0xBF;
    init_memory[0xFF24] = 0x77;
    init_memory[0xFF25] = 0xF3;
    init_memory[0xFF26] = 0xF1; // Not sure
    init_memory[0xFF40] = 0x91;
    init_memory[0xFF42] = 0x00;
    init_memory[0xFF43] = 0x00;
    init_memory[0xFF45] = 0x00;
    init_memory[0xFF47] = 0xFC;
    init_memory[0xFF48] = 0xFF;
    init_memory[0xFF49] = 0xFF;
    init_memory[0xFF4A] = 0x00;
    init_memory[0xFF4B] = 0x00;
    init_memory[0xFFFF] = 0x00;
    memory.load_memory(init_memory);
}

void gb::CPU::cycle() {
    // For timing
    cycles++;
}

void gb::CPU::read_memory(word addr) {
    bus.set_read();
    bus.write_addr(addr);
    memory.read_bus();
    current = bus.read_data();
    cycle();
}

void gb::CPU::write_memory(word addr, byte data) {
    bus.set_write();
    bus.write_addr(addr);
    bus.write_data(data);
    memory.read_bus();
    bus.set_read();
    cycle();
}

void gb::CPU::fetch() {
    read_memory(regs.PC++);
}

void gb::CPU::execute() {
    return;
}
