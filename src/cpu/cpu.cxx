#include "cpu.hxx"

gb::CPU::CPU(Bus& bus, Memory& memory) : bus(bus), memory(memory) {
    AF = 0;
    BC = 0;
    DE = 0;
    HL = 0;
    SP = 0;
    PC = 0;
    IR = 0;
    cycles = 0;
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
