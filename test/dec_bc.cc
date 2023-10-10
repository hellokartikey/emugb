#include "fixture.h"

using namespace gbc;
using Opcode_DEC_BC_Tests = CPUOpcodeTests;

TEST_F(Opcode_DEC_BC_Tests, OpcodeTest) { EXPECT_EQ(DEC_BC, 0x0b); }

TEST_F(Opcode_DEC_BC_Tests, BasicTest) {
  /** setup - begin */
  cpu.registers({.BC = 0x1000});
  program_t program = {DEC_BC};
  mem.load_program(program);
  /** setup - end */

  /** expected - begin */
  cycles_t cycles = 2;
  registers_t registers{.BC = 0x0fff, .PC = 0x0001};
  /** expected - end */

  /** execute */
  cpu.execute(1);

  /** checks - begin */
  EXPECT_EQ(cpu.cycles(), cycles);
  EXPECT_EQ(cpu.registers(), registers);
  /** checks - end */
}
