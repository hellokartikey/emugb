#include <gtest/gtest.h>

#include "fixture.hxx"

using Opcode_LD_D_Test = CPUTest;

using namespace gb;

TEST_F(Opcode_LD_D_Test, LD_D_B_Test) {
  /** start - inline program */
  memory_t program = {LD_B_D8, 0xab, LD_D_B};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.D, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_D_Test, LD_D_C_Test) {
  /** start - inline program */
  memory_t program = {LD_C_D8, 0xab, LD_D_C};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.D, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_D_Test, LD_D_D_Test) {
  /** start - inline program */
  memory_t program = {LD_D_D8, 0xab, LD_D_D};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.D, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_D_Test, LD_D_E_Test) {
  /** start - inline program */
  memory_t program = {LD_E_D8, 0xab, LD_D_E};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.D, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_D_Test, LD_D_H_Test) {
  /** start - inline program */
  memory_t program = {LD_H_D8, 0xab, LD_D_H};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.D, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_D_Test, LD_D_L_Test) {
  /** start - inline program */
  memory_t program = {LD_L_D8, 0xab, LD_D_L};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.D, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_D_Test, LD_D_AHL_Test) {
  /** start - inline program */
  memory_t program = {LD_HL_D16, 0x34, 0x12, LD_AHL_D8, 0xab, LD_D_AHL};
  memory.load_memory(program);
  cycles_t steps = 8;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.D, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_D_Test, LD_D_A_Test) {
  /** start - inline program */
  memory_t program = {LD_A_D8, 0xab, LD_D_A};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.D, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}
