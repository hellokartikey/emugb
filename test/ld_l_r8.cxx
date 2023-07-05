#include <gtest/gtest.h>

#include "fixture.hxx"

using Opcode_LD_L_Test = CPUTest;

using namespace gb;

TEST_F(Opcode_LD_L_Test, LD_L_B_Test) {
  /** start - inline program */
  memory_t program = {LD_B_D8, 0xab, LD_L_B};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.L, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_L_Test, LD_L_C_Test) {
  /** start - inline program */
  memory_t program = {LD_C_D8, 0xab, LD_L_C};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.L, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_L_Test, LD_L_D_Test) {
  /** start - inline program */
  memory_t program = {LD_D_D8, 0xab, LD_L_D};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.L, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_L_Test, LD_L_E_Test) {
  /** start - inline program */
  memory_t program = {LD_E_D8, 0xab, LD_L_E};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.L, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_L_Test, LD_L_H_Test) {
  /** start - inline program */
  memory_t program = {LD_H_D8, 0xab, LD_L_H};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.L, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_L_Test, LD_L_L_Test) {
  /** start - inline program */
  memory_t program = {LD_L_D8, 0xab, LD_L_L};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.L, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_L_Test, LD_L_AHL_Test) {
  /** start - inline program */
  memory_t program = {LD_HL_D16, 0x34, 0x12, LD_AHL_D8, 0xab, LD_L_AHL};
  memory.load_memory(program);
  cycles_t steps = 8;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.L, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_L_Test, LD_L_A_Test) {
  /** start - inline program */
  memory_t program = {LD_A_D8, 0xab, LD_L_A};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.L, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}
