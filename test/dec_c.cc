#include "fixture.h"

using namespace gbc;
using Opcode_DEC_C_Tests = CPUOpcodeTests;

TEST_F(Opcode_DEC_C_Tests, OpcodeTest) { EXPECT_EQ(DEC_C, 0x0d); }

TEST_F(Opcode_DEC_C_Tests, BasicTest) {
  /** setup - begin */
  cpu.registers({.C = 0x11});
  program_t program = {DEC_C};
  mem.load_program(program);
  /** setup - end */

  /** expected - begin */
  cycles_t cycles = 1;
  registers_t registers{.n = 1, .C = 0x10, .PC = 0x0001};
  /** expected - end */

  /** execute */
  cpu.execute(1);

  /** checks - begin */
  EXPECT_EQ(cpu.cycles(), cycles);
  EXPECT_EQ(cpu.registers(), registers);
  /** checks - end */
}

TEST_F(Opcode_DEC_C_Tests, ZeroTest) {
  /** setup - begin */
  cpu.registers({.C = 0x01});
  program_t program = {DEC_C};
  mem.load_program(program);
  /** setup - end */

  /** expected - begin */
  cycles_t cycles = 1;
  registers_t registers{.h = 0, .n = 1, .z = 1, .C = 0x00, .PC = 0x0001};
  /** expected - end */

  /** execute */
  cpu.execute(1);

  /** checks - begin */
  EXPECT_EQ(cpu.cycles(), cycles);
  EXPECT_EQ(cpu.registers(), registers);
  /** checks - end */
}

TEST_F(Opcode_DEC_C_Tests, SubtractTest) {
  /** setup - begin */
  cpu.registers({.n = 0, .C = 0x11});
  program_t program = {DEC_C};
  mem.load_program(program);
  /** setup - end */

  /** expected - begin */
  cycles_t cycles = 1;
  registers_t registers{.n = 1, .C = 0x10, .PC = 0x0001};
  /** expected - end */

  /** execute */
  cpu.execute(1);

  /** checks - begin */
  EXPECT_EQ(cpu.cycles(), cycles);
  EXPECT_EQ(cpu.registers(), registers);
  /** checks - end */
}

TEST_F(Opcode_DEC_C_Tests, HalfCarryTest) {
  /** setup - begin */
  cpu.registers({.C = 0x10});
  program_t program = {DEC_C};
  mem.load_program(program);
  /** setup - end */

  /** expected - begin */
  cycles_t cycles = 1;
  registers_t registers{.h = 0, .n = 1, .C = 0x0f, .PC = 0x0001};
  /** expected - end */

  /** execute */
  cpu.execute(1);

  /** checks - begin */
  EXPECT_EQ(cpu.cycles(), cycles);
  EXPECT_EQ(cpu.registers(), registers);
  /** checks - end */
}
