#include "fixture.h"

using namespace gbc;
using Opcode_LD_BC_D16_Tests = CPUOpcodeTests;

TEST_F(Opcode_LD_BC_D16_Tests, OpcodeTest) { EXPECT_EQ(LD_BC_D16, 0x01); }

TEST_F(Opcode_LD_BC_D16_Tests, BasicTest) {
  /** setup - begin */
  cpu.registers({});
  program_t program = {LD_BC_D16, 0x34, 0x12};
  mem.load_program(program);
  /** setup - end */

  /** expected - begin */
  cycles_t cycles = 3;
  registers_t registers{.BC = 0x1234, .PC = 0x0003};
  /** expected - end */

  /** execute */
  cpu.execute(cycles);

  /** checks - begin */
  EXPECT_EQ(cpu.cycles(), cycles);
  EXPECT_EQ(cpu.registers(), registers);
  /** checks - end */
}
