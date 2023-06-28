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
    std::cout << "L: " << int(regs.L) << "\n";

    std::cout << "PC: " << int(regs.PC) << "\n";
    std::cout << "SP: " << int(regs.SP) << "\n";

    std::cout << "cycles: " << int(cycles) << "\n";
    std::cout << "current: " << int(current) << "\n";

    std::cout << std::dec;
    std::cout << std::endl;
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
    regs.PC = 0x0000; // PC will be set when attaching cartridge
    regs.AF = 0x11B0;
    regs.BC = 0x0013;
    regs.DE = 0x00D8;
    regs.HL = 0x014D;
    regs.SP = 0xFFFE;

    memory_t init_memory = {0};
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
    init_memory[0xFF26] = 0xF1;
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

void gb::CPU::read_memory(gb::word addr) {
    bus.set_read();
    bus.write_addr(addr);
    memory.read_bus();
    current = bus.read_data();
    cycle();
}

void gb::CPU::write_memory(gb::word addr, gb::byte data) {
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

void gb::CPU::execute(gb::cycles_t steps) {
    while (steps > 0 ? cycles < steps : true) {
        fetch();
        switch (current) {
            case NOP: nop(); break;
            case STOP: stop(); break;

            case LD_BC_D16: ld_r16_d16(regs.BC); break;
            case LD_DE_D16: ld_r16_d16(regs.DE); break;
            case LD_HL_D16: ld_r16_d16(regs.HL); break;
            case LD_SP_D16: ld_r16_d16(regs.SP); break;
            case LD_A16_SP: ld_a16_r16(regs.SP); break;
            case LD_HL_SP_R8: ld_r16_r16_r8(regs.HL, regs.SP);
            case LD_SP_HL:  ld_r16_r16(regs.SP, regs.HL); break;

            case LD_B_D8:   ld_r8_d8(regs.B); break;
            case LD_C_D8:   ld_r8_d8(regs.C); break;
            case LD_D_D8:   ld_r8_d8(regs.D); break;
            case LD_E_D8:   ld_r8_d8(regs.E); break;
            case LD_H_D8:   ld_r8_d8(regs.H); break;
            case LD_L_D8:   ld_r8_d8(regs.L); break;
            case LD_AHL_D8: ld_a16_d8(regs.HL); break;
            case LD_A_D8:   ld_r8_d8(regs.A); break;

            case LD_B_B:   ld_r8_r8(regs.B, regs.B); break;
            case LD_B_C:   ld_r8_r8(regs.B, regs.C); break;
            case LD_B_D:   ld_r8_r8(regs.B, regs.D); break;
            case LD_B_E:   ld_r8_r8(regs.B, regs.E); break;
            case LD_B_H:   ld_r8_r8(regs.B, regs.H); break;
            case LD_B_L:   ld_r8_r8(regs.B, regs.L); break;
            case LD_B_AHL: ld_r8_ar16(regs.B, regs.HL); break;
            case LD_B_A:   ld_r8_r8(regs.B, regs.A); break;

            case LD_C_B:   ld_r8_r8(regs.C, regs.B); break;
            case LD_C_C:   ld_r8_r8(regs.C, regs.C); break;
            case LD_C_D:   ld_r8_r8(regs.C, regs.D); break;
            case LD_C_E:   ld_r8_r8(regs.C, regs.E); break;
            case LD_C_H:   ld_r8_r8(regs.C, regs.H); break;
            case LD_C_L:   ld_r8_r8(regs.C, regs.L); break;
            case LD_C_AHL: ld_r8_ar16(regs.C, regs.HL); break;
            case LD_C_A:   ld_r8_r8(regs.C, regs.A); break;

            case LD_D_B:   ld_r8_r8(regs.D, regs.B); break;
            case LD_D_C:   ld_r8_r8(regs.D, regs.C); break;
            case LD_D_D:   ld_r8_r8(regs.D, regs.D); break;
            case LD_D_E:   ld_r8_r8(regs.D, regs.E); break;
            case LD_D_H:   ld_r8_r8(regs.D, regs.H); break;
            case LD_D_L:   ld_r8_r8(regs.D, regs.L); break;
            case LD_D_AHL: ld_r8_ar16(regs.D, regs.HL); break;
            case LD_D_A:   ld_r8_r8(regs.D, regs.A); break;

            case LD_E_B:   ld_r8_r8(regs.E, regs.B); break;
            case LD_E_C:   ld_r8_r8(regs.E, regs.C); break;
            case LD_E_D:   ld_r8_r8(regs.E, regs.D); break;
            case LD_E_E:   ld_r8_r8(regs.E, regs.E); break;
            case LD_E_H:   ld_r8_r8(regs.E, regs.H); break;
            case LD_E_L:   ld_r8_r8(regs.E, regs.L); break;
            case LD_E_AHL: ld_r8_ar16(regs.E, regs.HL); break;
            case LD_E_A:   ld_r8_r8(regs.E, regs.A); break;

            case LD_H_B:   ld_r8_r8(regs.H, regs.B); break;
            case LD_H_C:   ld_r8_r8(regs.H, regs.C); break;
            case LD_H_D:   ld_r8_r8(regs.H, regs.D); break;
            case LD_H_E:   ld_r8_r8(regs.H, regs.E); break;
            case LD_H_H:   ld_r8_r8(regs.H, regs.H); break;
            case LD_H_L:   ld_r8_r8(regs.H, regs.L); break;
            case LD_H_AHL: ld_r8_ar16(regs.H, regs.HL); break;
            case LD_H_A:   ld_r8_r8(regs.H, regs.A); break;

            case LD_L_B:   ld_r8_r8(regs.L, regs.B); break;
            case LD_L_C:   ld_r8_r8(regs.L, regs.C); break;
            case LD_L_D:   ld_r8_r8(regs.L, regs.D); break;
            case LD_L_E:   ld_r8_r8(regs.L, regs.E); break;
            case LD_L_H:   ld_r8_r8(regs.L, regs.H); break;
            case LD_L_L:   ld_r8_r8(regs.L, regs.L); break;
            case LD_L_AHL: ld_r8_ar16(regs.L, regs.HL); break;
            case LD_L_A:   ld_r8_r8(regs.L, regs.A); break;

            case LD_AHL_B:   ld_a16_r8(regs.HL, regs.B); break;
            case LD_AHL_C:   ld_a16_r8(regs.HL, regs.C); break;
            case LD_AHL_D:   ld_a16_r8(regs.HL, regs.D); break;
            case LD_AHL_E:   ld_a16_r8(regs.HL, regs.E); break;
            case LD_AHL_H:   ld_a16_r8(regs.HL, regs.H); break;
            case LD_AHL_L:   ld_a16_r8(regs.HL, regs.L); break;
            case LD_AHL_A:   ld_a16_r8(regs.HL, regs.A); break;
            case LD_ABC_A:   ld_a16_r8(regs.BC, regs.A); break;
            case LD_ADE_A:   ld_a16_r8(regs.DE, regs.A); break;
            case LD_AHLP_A:  ld_a16_r8(regs.HL++, regs.A); break;
            case LD_AHLM_A:  ld_a16_r8(regs.HL--, regs.A); break;

            case LDH_A8_A:   ld_a8_r8(regs.A); break;
            case LDH_A_A8:   ld_r8_a8(regs.A); break;
            case LD_AC_A:    ld_ar8_r8(regs.C, regs.A); break;
            case LD_A_AC:    ld_r8_ar8(regs.A, regs.C); break;
            case LD_A16_A:   ld_a16_r8(regs.A); break;
            case LD_A_A16:   ld_r8_a16(regs.A); break;

            case LD_A_B:   ld_r8_r8(regs.A, regs.B); break;
            case LD_A_C:   ld_r8_r8(regs.A, regs.C); break;
            case LD_A_D:   ld_r8_r8(regs.A, regs.D); break;
            case LD_A_E:   ld_r8_r8(regs.A, regs.E); break;
            case LD_A_H:   ld_r8_r8(regs.A, regs.H); break;
            case LD_A_L:   ld_r8_r8(regs.A, regs.L); break;
            case LD_A_AHL: ld_r8_ar16(regs.A, regs.HL); break;
            case LD_A_A:   ld_r8_r8(regs.A, regs.A); break;
            case LD_A_ABC: ld_r8_ar16(regs.A, regs.BC); break;
            case LD_A_ADE: ld_r8_ar16(regs.A, regs.DE); break;
            case LD_A_AHLP: ld_r8_ar16(regs.A, regs.HL++); break;
            case LD_A_AHLM: ld_r8_ar16(regs.A, regs.HL--); break;

            case PUSH_BC: push(regs.BC); break;
            case PUSH_DE: push(regs.DE); break;
            case PUSH_HL: push(regs.HL); break;
            case PUSH_AF: push(regs.AF); break;

            case POP_BC: pop(regs.BC); break;
            case POP_DE: pop(regs.DE); break;
            case POP_HL: pop(regs.HL); break;
            case POP_AF: pop(regs.AF); break;

            case INC_BC: inc(regs.BC); break;
            case INC_DE: inc(regs.DE); break;
            case INC_HL: inc(regs.HL); break;
            case INC_SP: inc(regs.SP); break;

            case RST_00: rst(0x0000); break;
            case RST_10: rst(0x0010); break;
            case RST_20: rst(0x0020); break;
            case RST_30: rst(0x0030); break;
            case RST_08: rst(0x0008); break;
            case RST_18: rst(0x0018); break;
            case RST_28: rst(0x0028); break;
            case RST_38: rst(0x0038); break;

            default: unrecognized(); return;
        }
    }
}

void gb::CPU::unrecognized() {
    std::cout << "Unrecognized Opcode: ";
    std::cout << std::hex << int(current) << std::dec << "\n";
}

void gb::CPU::nop() {
    std::cout << "NOP\n";
    return;
}

void gb::CPU::stop() {
    while (true) {}
}

void gb::CPU::ld_r16_d16(gb::word& r16) {
    gb::word d16;
    fetch();
    d16 = current;
    fetch();
    d16 += (gb::word(current) << 8);
    r16 = d16;
}

void gb::CPU::ld_r8_d8(gb::byte& r8) {
    fetch();
    r8 = current;
}

void gb::CPU::ld_a16_d8(gb::word& a16) {
    fetch();
    write_memory(a16, current);
}

void gb::CPU::ld_r8_r8(gb::byte& r8_dst, gb::byte r8_src) {
    r8_dst = r8_src;
}

void gb::CPU::ld_r8_ar16(gb::byte& r8, gb::word a16) {
    read_memory(a16);
    r8 = current;
}

void gb::CPU::ld_a16_r8(gb::word a16, gb::byte r8) {
    write_memory(a16, r8);
}

void gb::CPU::ld_a16_r16(gb::word& r16) {
    word addr = 0x0000;
    fetch();
    addr += current;
    fetch();
    addr += word(current) << 8;

    byte msb = regs.SP >> 8;
    byte lsb = regs.SP;

    write_memory(addr, lsb);
    write_memory(addr+1, msb);
}

void gb::CPU::ld_r16_r16_r8(word& r16_dst, word r16_src) {
    bool h, c;

    word dst_bef = r16_src;
    fetch();
    word dst_aff = r16_src + current;
    cycle();

    h = half_carry_add(r16_src, current);
    c = carry_add(r16_src, current);

    r16_dst = dst_aff;

    regs.z = 0;
    regs.n = 0;
    regs.h = h;
    regs.c = c;
}

void gb::CPU::ld_r16_r16(word& r16_dst, word r16_src) {
    r16_dst = r16_src;
}

void gb::CPU::push(word r16) {
    byte lsb = r16;
    byte msb = r16 >> 8;

    cycle();

    write_memory(regs.SP--, msb);
    write_memory(regs.SP--, lsb);
}

void gb::CPU::pop(word& r16) {
    read_memory(++regs.SP);
    byte lsb = current;
    read_memory(++regs.SP);
    byte msb = current;

    r16 = (word(msb) << 8) + lsb;
}

void gb::CPU::ld_a8_r8(byte r8) {
    fetch();
    write_memory(0xff00 + current, r8);
}

void gb::CPU::ld_r8_a8(byte& r8) {
    fetch();
    read_memory(0xff00 + current);
    r8 = current;
}

void gb::CPU::ld_ar8_r8(byte ar8, byte r8) {
    write_memory(0xff00 + ar8, r8);
}

void gb::CPU::ld_r8_ar8(byte& r8, byte ar8) {
    read_memory(0xff00 + ar8);
    r8 = current;
}

void gb::CPU::ld_r8_a16(byte& r8) {
    word addr;

    fetch();
    addr = current;

    fetch();
    addr += (word(current) << 8);

    read_memory(addr);
    r8 = current;
}
void gb::CPU::ld_a16_r8(byte r8) {
    word addr;

    fetch();
    addr = current;

    fetch();
    addr += (word(current) << 8);

    write_memory(addr, r8);
}

void gb::CPU::inc(byte& r8) {}

void gb::CPU::inc(word& r16) {
    cycle();
    r16++;
}

void gb::CPU::rst(word addr) {
    push(regs.PC);
    regs.PC = addr;
}
