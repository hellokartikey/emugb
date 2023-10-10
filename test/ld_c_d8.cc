#include "fixture.h"

using namespace gbc;
using Opcode_LD_C_D8_Tests = CPUOpcodeTests;

TEST_F(Opcode_LD_C_D8_Tests, OpcodeTest) { EXPECT_EQ(LD_C_D8, 0x0e); }

TEST_F(Opcode_LD_C_D8_Tests, BasicTest) {
  /** setup - begin */
  cpu.registers({});
  program_t program = {LD_C_D8, 0x12};
  mem.load_program(program);
  /** setup - end */

  /** expected - begin */
  cycles_t cycles = 2;
  registers_t registers{.C = 0x12, .PC = 0x0002};
  /** expected - end */

  /** execute */
  cpu.execute(1);

  /** checks - begin */
  EXPECT_EQ(cpu.cycles(), cycles);
  EXPECT_EQ(cpu.registers(), registers);
  /** checks - end */
}
