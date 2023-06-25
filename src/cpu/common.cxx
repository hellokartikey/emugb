#include "common.hxx"

gb::byte gb::rand_byte() {
    return std::rand() % gb::max_byte;
}

gb::word gb::rand_word() {
    return std::rand() % gb::max_word;
}

bool gb::regs_iseq(gb::registers_t regs1, gb::registers_t regs2) {
    if (
        regs1.AF == regs2.AF && regs1.BC == regs2.BC &&
        regs1.DE == regs2.DE && regs1.HL == regs2.HL &&
        regs1.SP == regs2.SP && regs1.PC == regs2.PC
    ) {
        return true;
    }
    return false;
}
