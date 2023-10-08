#include "fixture.h"

using namespace gbc;
using Opcode_RLCA_Tests = CPUOpcodeTests;

TEST_F(Opcode_RLCA_Tests, OpcodeTest) { EXPECT_EQ(RLCA, 0x07); }

TEST_F(Opcode_RLCA_Tests, BasicTest) {
  /** setup - begin */
  cpu.registers({.A = 0x55});
  program_t program = {RLCA};
  mem.load_program(program);
  /** setup - end */

  /** expected - begin */
  cycles_t cycles = 1;
  registers_t registers{.A = 0xAA, .PC = 0x0001};
  /** expected - end */

  /** execute */
  cpu.execute(1);

  /** checks - begin */
  EXPECT_EQ(cpu.cycles(), cycles);
  EXPECT_EQ(cpu.registers(), registers);
  /** checks - end */
}

TEST_F(Opcode_RLCA_Tests, CarryTest) {
  /** setup - begin */
  cpu.registers({.A = 0xAA});
  program_t program = {RLCA};
  mem.load_program(program);
  /** setup - end */

  /** expected - begin */
  cycles_t cycles = 1;
  registers_t registers{.c = 1, .A = 0x55, .PC = 0x0001};
  /** expected - end */

  /** execute */
  cpu.execute(1);

  /** checks - begin */
  EXPECT_EQ(cpu.cycles(), cycles);
  EXPECT_EQ(cpu.registers(), registers);
  /** checks - end */
}
