#include "fixture.h"

using namespace gbc;
using Opcode_LD_ABC_A_Tests = CPUOpcodeTests;

TEST_F(Opcode_LD_ABC_A_Tests, OpcodeTest) { EXPECT_EQ(LD_ABC_A, 0x02); }

TEST_F(Opcode_LD_ABC_A_Tests, BasicTest) {
  /** setup - begin */
  cpu.registers({.A = 0x64, .BC = 0x1000});
  program_t program = {LD_ABC_A};
  mem.load_program(program);
  /** setup - end */

  /** expected - begin */
  cycles_t cycles = 2;
  registers_t registers{.A = 0x64, .BC = 0x1000, .PC = 0x0001};
  /** expected - end */

  /** execute */
  cpu.execute(1);

  /** checks - begin */
  EXPECT_EQ(cpu.cycles(), cycles);
  EXPECT_EQ(cpu.registers(), registers);
  /** checks - end */
}
