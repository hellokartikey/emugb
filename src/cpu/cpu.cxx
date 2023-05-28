#include "cpu.hxx"

void CPU::fetch() {
    cycles++;
    IR = memory.read(PC++);
}

void CPU::execute() {
    while (1) {
        fetch();
        switch (IR) {

        case LD_B_D8: ld(B); break;
        case LD_C_D8: ld(C); break;
        case LD_D_D8: ld(D); break;
        case LD_E_D8: ld(E); break;
        case LD_H_D8: ld(H); break;
        case LD_L_D8: ld(L); break;

        case LD_A_A: ld(A, A); break;
        case LD_A_B: ld(A, B); break;
        case LD_A_C: ld(A, C); break;
        case LD_A_D: ld(A, D); break;
        case LD_A_E: ld(A, E); break;
        case LD_A_H: ld(A, H); break;
        case LD_A_L: ld(A, L); break;
        case LD_A_HL: ld(A, HL); break;

        case HALT: return; break;
        }
    }
}

void CPU::ld(byte& reg) {
    fetch();
    reg = IR;
}

void CPU::ld(byte& reg, byte data) {
    reg = data;
}

void CPU::ld(byte& reg, word addr) {
    cycles++;
    reg = memory.read(addr);
}

void CPU::halt() {
    return;
}
