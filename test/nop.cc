#include "fixture.h"
#include "types.h"

using Opcode_NOP_Tests = CPUOpcodeTests;

TEST_F(Opcode_NOP_Tests, OpcodeTest) { EXPECT_EQ(NOP, 0x00); }

TEST_F(Opcode_NOP_Tests, BasicTest) {
  /** setup - begin */
  cpu.registers({});
  program_t program = {NOP};
  mem.load_program(program);
  /** setup - end */

  /** expected - begin */
  cycles_t cycles = 1;
  registers_t registers{.PC = 0x0001};
  /** expected - end */

  /** execute */
  cpu.execute(1);

  /** checks - begin */
  EXPECT_EQ(cpu.cycles(), cycles);
  EXPECT_EQ(cpu.registers(), registers);
  /** checks - end */
}
