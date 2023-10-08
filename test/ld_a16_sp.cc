#include "fixture.h"

using namespace gbc;
using Opcode_LD_A16_SP_Tests = CPUOpcodeTests;

TEST_F(Opcode_LD_A16_SP_Tests, OpcodeTest) { EXPECT_EQ(LD_A16_SP, 0x08); }

TEST_F(Opcode_LD_A16_SP_Tests, BasicTest) {
  /** setup - begin */
  cpu.registers({.SP = 0x1234});
  program_t program = {LD_A16_SP, 0x34, 0x12};
  mem.load_program(program);
  /** setup - end */

  /** expected - begin */
  cycles_t cycles = 5;
  registers_t registers{.SP = 0x1234, .PC = 0x0003};
  /** expected - end */

  /** execute */
  cpu.execute(1);

  /** checks - begin */
  EXPECT_EQ(cpu.cycles(), cycles);
  EXPECT_EQ(cpu.registers(), registers);
  EXPECT_EQ(mem[0x1234], 0x34);
  EXPECT_EQ(mem[0x1235], 0x12);
  /** checks - end */
}
