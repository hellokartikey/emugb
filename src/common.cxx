#include "common.hxx"

namespace gb {
byte rand_byte() { return std::rand() % max_byte; }

word rand_word() { return std::rand() % max_word; }

bool regs_iseq(registers_t regs1, registers_t regs2) {
  if (regs1.AF == regs2.AF && regs1.BC == regs2.BC && regs1.DE == regs2.DE &&
      regs1.HL == regs2.HL && regs1.SP == regs2.SP && regs1.PC == regs2.PC) {
    return true;
  }
  return false;
}

bool carry_add(byte op1, byte op2) { return (op1 & 0x80) * (op2 & 0x80); }

bool half_carry_add(byte op1, byte op2) { return (op1 & 0x08) * (op2 & 0x08); }

bool half_carry_sub(byte op1, byte op2) {
  return ((op1 & 0x08) == 0) * ((op2 & 0x08) != 0);
}
}  // namespace gb
