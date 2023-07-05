#include <gtest/gtest.h>

#include "fixture.hxx"

using Opcode_DEC_Test = CPUTest;

using namespace gb;

TEST_F(Opcode_DEC_Test, DEC_BC_Test) {
  /** start - inline program */
  memory_t program = {DEC_BC};
  memory.load_memory(program);
  cycles_t steps = 2;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.BC, 0xFFFF);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_DEC_Test, DEC_DE_Test) {
  /** start - inline program */
  memory_t program = {DEC_DE};
  memory.load_memory(program);
  cycles_t steps = 2;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.DE, 0xffff);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_DEC_Test, DEC_HL_Test) {
  /** start - inline program */
  memory_t program = {DEC_HL};
  memory.load_memory(program);
  cycles_t steps = 2;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.HL, 0xffff);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_DEC_Test, DEC_SP_Test) {
  /** start - inline program */
  memory_t program = {DEC_SP};
  memory.load_memory(program);
  cycles_t steps = 2;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.SP, 0xffff);
  EXPECT_EQ(steps, cpu.get_cycles());
}
