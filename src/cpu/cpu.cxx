#include "cpu.hxx"

gb::CPU::CPU(Bus& bus, Memory& memory) : bus(bus), memory(memory) {
    reset();
    init();
}

void gb::CPU::reset() {
    AF = 0;
    BC = 0;
    DE = 0;
    HL = 0;
    SP = 0;
    PC = 0;
    IR = 0;
    cycles = 0;
}

void gb::CPU::init() {
    PC = 0x0100;
    A = 0x11;
    F = 0xB0;
    BC = 0x0013;
    DE = 0x00D8;
    HL = 0x014D;
    SP = 0xFFFE;
    
    gb::memory init_memory;
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

void gb::CPU::read_memory(word addr) {
    bus.set_read();
    bus.write_addr(addr);
    memory.read_bus();
    IR = bus.read_data();
    cycles++;
}

void gb::CPU::write_memory(word addr, byte data) {
    bus.set_write();
    bus.write_addr(addr);
    bus.write_data(data);
    memory.read_bus();
    bus.set_read();
    cycles++;
}

void gb::CPU::fetch() {
    read_memory(PC++);
}

void gb::CPU::execute() {
    while (1) {
        fetch();
        switch (IR) {

        case LD_B_D8: ld(B); break;
        case LD_C_D8: ld(C); break;
        case LD_D_D8: ld(D); break;
        case LD_E_D8: ld(E); break;
        case LD_H_D8: ld(H); break;
        case LD_L_D8: ld(L); break;

        case LD_A_A:  ld(A, A); break;
        case LD_A_B:  ld(A, B); break;
        case LD_A_C:  ld(A, C); break;
        case LD_A_D:  ld(A, D); break;
        case LD_A_E:  ld(A, E); break;
        case LD_A_H:  ld(A, H); break;
        case LD_A_L:  ld(A, L); break;
        case LD_A_HL: ld(A, HL); break;

        case INC_A: inc(A); break;
        case INC_B: inc(B); break;
        case INC_C: inc(C); break;
        case INC_D: inc(D); break;
        case INC_E: inc(E); break;
        case INC_H: inc(H); break;
        case INC_L: inc(L); break;

        case HALT: return; break;
        case NOP:  continue; break;

        default: return; break;
        }
    }
}

void gb::CPU::ld(byte& reg) {
    fetch();
    reg = IR;
}

void gb::CPU::ld(byte& reg, byte data) {
    reg = data;
}

void gb::CPU::ld(byte& reg, word addr) {
    cycles++;
    // bus.write_addr(addr);
    // reg = bus.read_data();
}

void gb::CPU::halt() {
    return;
}

void gb::CPU::inc(byte& reg) {
    reg++;
}
