#include "fixture.h"

using namespace gbc;
using Opcode_ADD_HL_BC_Tests = CPUOpcodeTests;

TEST_F(Opcode_ADD_HL_BC_Tests, OpcodeTest) { EXPECT_EQ(ADD_HL_BC, 0x09); }

TEST_F(Opcode_ADD_HL_BC_Tests, BasicTest) {
  /** setup - begin */
  cpu.registers({.BC = 0x1010, .HL = 0x1010});
  program_t program = {ADD_HL_BC};
  mem.load_program(program);
  /** setup - end */

  /** expected - begin */
  cycles_t cycles = 2;
  registers_t registers{.BC = 0x1010, .HL = 0x2020, .PC = 0x0001};
  /** expected - end */

  /** execute */
  cpu.execute(1);

  /** checks - begin */
  EXPECT_EQ(cpu.cycles(), cycles);
  EXPECT_EQ(cpu.registers(), registers);
  /** checks - end */
}

TEST_F(Opcode_ADD_HL_BC_Tests, SubtractTest) {
  /** setup - begin */
  cpu.registers({.n = 1, .BC = 0x1010, .HL = 0x1010});
  program_t program = {ADD_HL_BC};
  mem.load_program(program);
  /** setup - end */

  /** expected - begin */
  cycles_t cycles = 2;
  registers_t registers{.n = 0, .BC = 0x1010, .HL = 0x2020, .PC = 0x0001};
  /** expected - end */

  /** execute */
  cpu.execute(1);

  /** checks - begin */
  EXPECT_EQ(cpu.cycles(), cycles);
  EXPECT_EQ(cpu.registers(), registers);
  /** checks - end */
}

TEST_F(Opcode_ADD_HL_BC_Tests, HalfCarryTest) {
  /** setup - begin */
  cpu.registers({.BC = 0x0001, .HL = 0x0fff});
  program_t program = {ADD_HL_BC};
  mem.load_program(program);
  /** setup - end */

  /** expected - begin */
  cycles_t cycles = 2;
  registers_t registers{.h = 1, .BC = 0x0001, .HL = 0x1000, .PC = 0x0001};
  /** expected - end */

  /** execute */
  cpu.execute(1);

  /** checks - begin */
  EXPECT_EQ(cpu.cycles(), cycles);
  EXPECT_EQ(cpu.registers(), registers);
  /** checks - end */
}

TEST_F(Opcode_ADD_HL_BC_Tests, CarryTest) {
  /** setup - begin */
  cpu.registers({.BC = 0x0001, .HL = 0xffff});
  program_t program = {ADD_HL_BC};
  mem.load_program(program);
  /** setup - end */

  /** expected - begin */
  cycles_t cycles = 2;
  registers_t registers{
      .c = 1, .h = 1, .BC = 0x0001, .HL = 0x0000, .PC = 0x0001};
  /** expected - end */

  /** execute */
  cpu.execute(1);

  /** checks - begin */
  EXPECT_EQ(cpu.cycles(), cycles);
  EXPECT_EQ(cpu.registers(), registers);
  /** checks - end */
}
