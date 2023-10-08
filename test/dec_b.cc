#include "fixture.h"

using namespace gbc;
using Opcode_DEC_B_Tests = CPUOpcodeTests;

TEST_F(Opcode_DEC_B_Tests, OpcodeTest) { EXPECT_EQ(DEC_B, 0x05); }

TEST_F(Opcode_DEC_B_Tests, BasicTest) {
  /** setup - begin */
  cpu.registers({.B = 0x11});
  program_t program = {DEC_B};
  mem.load_program(program);
  /** setup - end */

  /** expected - begin */
  cycles_t cycles = 1;
  registers_t registers{.n = 1, .B = 0x10, .PC = 0x0001};
  /** expected - end */

  /** execute */
  cpu.execute(1);

  /** checks - begin */
  EXPECT_EQ(cpu.cycles(), cycles);
  EXPECT_EQ(cpu.registers(), registers);
  /** checks - end */
}

TEST_F(Opcode_DEC_B_Tests, ZeroTest) {
  /** setup - begin */
  cpu.registers({.B = 0x01});
  program_t program = {DEC_B};
  mem.load_program(program);
  /** setup - end */

  /** expected - begin */
  cycles_t cycles = 1;
  registers_t registers{.h = 0, .n = 1, .z = 1, .B = 0x00, .PC = 0x0001};
  /** expected - end */

  /** execute */
  cpu.execute(1);

  /** checks - begin */
  EXPECT_EQ(cpu.cycles(), cycles);
  EXPECT_EQ(cpu.registers(), registers);
  /** checks - end */
}

TEST_F(Opcode_DEC_B_Tests, SubtractTest) {
  /** setup - begin */
  cpu.registers({.n = 0, .B = 0x11});
  program_t program = {DEC_B};
  mem.load_program(program);
  /** setup - end */

  /** expected - begin */
  cycles_t cycles = 1;
  registers_t registers{.n = 1, .B = 0x10, .PC = 0x0001};
  /** expected - end */

  /** execute */
  cpu.execute(1);

  /** checks - begin */
  EXPECT_EQ(cpu.cycles(), cycles);
  EXPECT_EQ(cpu.registers(), registers);
  /** checks - end */
}

TEST_F(Opcode_DEC_B_Tests, HalfCarryTest) {
  /** setup - begin */
  cpu.registers({.B = 0x10});
  program_t program = {DEC_B};
  mem.load_program(program);
  /** setup - end */

  /** expected - begin */
  cycles_t cycles = 1;
  registers_t registers{.h = 1, .n = 1, .B = 0x0f, .PC = 0x0001};
  /** expected - end */

  /** execute */
  cpu.execute(1);

  /** checks - begin */
  EXPECT_EQ(cpu.cycles(), cycles);
  EXPECT_EQ(cpu.registers(), registers);
  /** checks - end */
}
