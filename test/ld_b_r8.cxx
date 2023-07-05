#include <gtest/gtest.h>

#include "fixture.hxx"

using Opcode_LD_B_Test = CPUTest;

using namespace gb;

TEST_F(Opcode_LD_B_Test, LD_B_B_Test) {
  /** start - inline program */
  memory_t program = {LD_B_D8, 0xab, LD_B_B};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.B, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_B_Test, LD_B_C_Test) {
  /** start - inline program */
  memory_t program = {LD_C_D8, 0xab, LD_B_C};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.B, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_B_Test, LD_B_D_Test) {
  /** start - inline program */
  memory_t program = {LD_D_D8, 0xab, LD_B_D};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.B, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_B_Test, LD_B_E_Test) {
  /** start - inline program */
  memory_t program = {LD_E_D8, 0xab, LD_B_E};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.B, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_B_Test, LD_B_H_Test) {
  /** start - inline program */
  memory_t program = {LD_H_D8, 0xab, LD_B_H};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.B, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_B_Test, LD_B_L_Test) {
  /** start - inline program */
  memory_t program = {LD_L_D8, 0xab, LD_B_L};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.B, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_B_Test, LD_B_AHL_Test) {
  /** start - inline program */
  memory_t program = {LD_HL_D16, 0x34, 0x12, LD_AHL_D8, 0xab, LD_B_AHL};
  memory.load_memory(program);
  cycles_t steps = 8;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.B, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_B_Test, LD_B_A_Test) {
  /** start - inline program */
  memory_t program = {LD_A_D8, 0xab, LD_B_A};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.B, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}
