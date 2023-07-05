#include <gtest/gtest.h>

#include "fixture.hxx"

using Opcode_LD_R16_D16_Test = CPUTest;

using namespace gb;

TEST_F(Opcode_LD_R16_D16_Test, LD_BC_D16_Test) {
  /** start - inline program */
  memory_t program = {LD_BC_D16, 0xcd, 0xab};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.BC, 0xABCD);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_R16_D16_Test, LD_DE_D16_Test) {
  /** start - inline program */
  memory_t program = {LD_DE_D16, 0xcd, 0xab};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.DE, 0xABCD);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_R16_D16_Test, LD_HL_D16_Test) {
  /** start - inline program */
  memory_t program = {LD_HL_D16, 0xcd, 0xab};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.HL, 0xABCD);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_R16_D16_Test, LD_SP_D16_Test) {
  /** start - inline program */
  memory_t program = {LD_SP_D16, 0xcd, 0xab};
  memory.load_memory(program);
  cycles_t steps = 3;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.SP, 0xABCD);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_R16_D16_Test, LD_A16_SP_Test) {
  /** start - inline program */
  memory_t program = {LD_SP_D16, 0xcd, 0xab, LD_A16_SP, 0x34, 0x12};
  memory.load_memory(program);
  cycles_t steps = 8;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();
  memory_t mem = memory.dump_memory();

  EXPECT_EQ(mem[0x1234], 0xCD);
  EXPECT_EQ(mem[0x1235], 0xAB);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_R16_D16_Test, LD_HL_SP_R8_BasicTest) {
  /** start - inline program */
  memory_t program = {LD_SP_D16, 0x34, 0x12, LD_HL_SP_R8, 0x0b};
  memory.load_memory(program);
  cycles_t steps = 6;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();
  memory_t mem = memory.dump_memory();

  EXPECT_EQ(regs.HL, 0x123f);
  EXPECT_EQ(regs.z, 0);
  EXPECT_EQ(regs.n, 0);
  EXPECT_EQ(regs.h, 0);
  EXPECT_EQ(regs.c, 0);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_R16_D16_Test, LD_HL_SP_R8_HalfCarryTest) {
  /** start - inline program */
  memory_t program = {LD_SP_D16, 0x08, 0x00, LD_HL_SP_R8, 0x08};
  memory.load_memory(program);
  cycles_t steps = 6;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();
  memory_t mem = memory.dump_memory();

  EXPECT_EQ(regs.HL, 0x0010);
  EXPECT_EQ(regs.z, 0);
  EXPECT_EQ(regs.n, 0);
  EXPECT_EQ(regs.h, 1);
  EXPECT_EQ(regs.c, 0);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_R16_D16_Test, LD_HL_SP_R8_CarryTest) {
  /** start - inline program */
  memory_t program = {LD_SP_D16, 0x80, 0x00, LD_HL_SP_R8, 0x80};
  memory.load_memory(program);
  cycles_t steps = 6;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();
  memory_t mem = memory.dump_memory();

  EXPECT_EQ(regs.HL, 0x0100);
  EXPECT_EQ(regs.z, 0);
  EXPECT_EQ(regs.n, 0);
  EXPECT_EQ(regs.h, 0);
  EXPECT_EQ(regs.c, 1);
  EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_R16_D16_Test, LD_SP_HL_Test) {
  /** start - inline program */
  memory_t program = {LD_HL_D16, 0xcd, 0xab, LD_SP_HL};
  memory.load_memory(program);
  cycles_t steps = 4;
  /** end   - inline program */

  cpu.execute(steps);
  registers_t regs = cpu.get_regs();

  EXPECT_EQ(regs.SP, 0xABCD);
  EXPECT_EQ(steps, cpu.get_cycles());
}
