#include <gtest/gtest.h>

#include "fixture.hxx"

using Opcode_LD_A_Test = CPUTest;

using namespace gb;

TEST_F(Opcode_LD_A_Test, LD_A_B_Test) {
  /** start - inline program */
  memory_t program = {LD_B_D8, 0xab, LD_A_B};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.A, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_A_Test, LD_A_C_Test) {
  /** start - inline program */
  memory_t program = {LD_C_D8, 0xab, LD_A_C};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.A, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_A_Test, LD_A_D_Test) {
  /** start - inline program */
  memory_t program = {LD_D_D8, 0xab, LD_A_D};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.A, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_A_Test, LD_A_E_Test) {
  /** start - inline program */
  memory_t program = {LD_E_D8, 0xab, LD_A_E};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.A, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_A_Test, LD_A_H_Test) {
  /** start - inline program */
  memory_t program = {LD_H_D8, 0xab, LD_A_H};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.A, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_A_Test, LD_A_L_Test) {
  /** start - inline program */
  memory_t program = {LD_L_D8, 0xab, LD_A_L};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.A, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_A_Test, LD_A_AHL_Test) {
  /** start - inline program */
  memory_t program = {LD_HL_D16, 0x34, 0x12, LD_AHL_D8, 0xab, LD_A_AHL};
  memory.load_memory(program);
  cycles_t steps = 8;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.A, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_A_Test, LD_A_A_Test) {
  /** start - inline program */
  memory_t program = {LD_A_D8, 0xab, LD_A_A};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.A, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_A_Test, LD_A_ABC_Test) {
  /** start - inline program */
  memory_t program = {LD_BC_D16, 0x34,    0x12, LD_A_D8, 0xab,
                      LD_ABC_A,  LD_A_D8, 0x00, LD_A_ABC};
  memory.load_memory(program);
  cycles_t steps = 11;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.A, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_A_Test, LD_A_ADE_Test) {
  /** start - inline program */
  memory_t program = {LD_DE_D16, 0x34,    0x12, LD_A_D8, 0xab,
                      LD_ADE_A,  LD_A_D8, 0x00, LD_A_ADE};
  memory.load_memory(program);
  cycles_t steps = 11;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.A, 0xab);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_A_Test, LD_A_AHLP_Test) {
  /** start - inline program */
  memory_t program = {LD_HL_D16, 0x34, 0x12, LD_AHL_D8, 0xab, LD_A_AHLP};
  memory.load_memory(program);
  cycles_t steps = 8;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.A, 0xab);
  EXPECT_EQ(regs.HL, 0x1235);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_A_Test, LD_A_AHLM_Test) {
  /** start - inline program */
  memory_t program = {LD_HL_D16, 0x34, 0x12, LD_AHL_D8, 0xab, LD_A_AHLM};
  memory.load_memory(program);
  cycles_t steps = 8;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.A, 0xab);
  EXPECT_EQ(regs.HL, 0x1233);
  EXPECT_EQ(steps, cpu.get_cycles());
}
