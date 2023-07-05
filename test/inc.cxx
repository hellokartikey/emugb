#include <gtest/gtest.h>

#include "fixture.hxx"

using Opcode_INC_Test = CPUTest;

using namespace gb;

TEST_F(Opcode_INC_Test, INC_BC_Test) {
  /** start - inline program */
  memory_t program = {INC_BC};
  memory.load_memory(program);
  cycles_t steps = 2;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.BC, 0x0001);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_INC_Test, INC_DE_Test) {
  /** start - inline program */
  memory_t program = {INC_DE};
  memory.load_memory(program);
  cycles_t steps = 2;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.DE, 0x0001);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_INC_Test, INC_HL_Test) {
  /** start - inline program */
  memory_t program = {INC_HL};
  memory.load_memory(program);
  cycles_t steps = 2;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.HL, 0x0001);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_INC_Test, INC_SP_Test) {
  /** start - inline program */
  memory_t program = {INC_SP};
  memory.load_memory(program);
  cycles_t steps = 2;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.SP, 0x0001);
  EXPECT_EQ(steps, cpu.get_cycles());
}
