#include <gtest/gtest.h>

#include "fixture.hxx"

using Opcode_JP_Test = CPUTest;

using namespace gb;

TEST_F(Opcode_JP_Test, JP_A16_Test) {
  /** start - inline program */
  registers_t status;
  status.PC = 0x0000;
  memory_t program = {JP_A16, 0x00, 0x10};
  cycles_t steps = 4;
  cpu.set_regs(status);
  memory.load_memory(program);
  /** end   - inline program */

  cpu.execute(1);

  registers_t regs = cpu.get_regs();
  memory_t mem = memory.dump_memory();

  EXPECT_EQ(regs.PC, 0x1001);
  EXPECT_EQ(cpu.get_cycles(), steps);
}

TEST_F(Opcode_JP_Test, JP_AHL_Test) {
  /** start - inline program */
  registers_t status;
  status.PC = 0x0000;
  status.HL = 0x1000;
  memory_t program = {JP_AHL};
  cycles_t steps = 1;
  cpu.set_regs(status);
  memory.load_memory(program);
  /** end   - inline program */

  cpu.execute(1);

  registers_t regs = cpu.get_regs();
  memory_t mem = memory.dump_memory();

  EXPECT_EQ(regs.PC, 0x1001);
  EXPECT_EQ(cpu.get_cycles(), steps);
}

TEST_F(Opcode_JP_Test, JP_NZ_A16_NoZero_Test) {
  /** start - inline program */
  registers_t status;
  status.PC = 0x0000;
  status.z = 0;
  memory_t program = {JP_NZ_A16, 0x00, 0x10};
  cycles_t steps = 4;
  cpu.set_regs(status);
  memory.load_memory(program);
  /** end   - inline program */

  cpu.execute(1);

  registers_t regs = cpu.get_regs();
  memory_t mem = memory.dump_memory();

  EXPECT_EQ(regs.PC, 0x1001);
  EXPECT_EQ(cpu.get_cycles(), steps);
}

TEST_F(Opcode_JP_Test, JP_NZ_A16_Zero_Test) {
  /** start - inline program */
  registers_t status;
  status.PC = 0x0000;
  status.z = 1;
  memory_t program = {JP_NZ_A16, 0x00, 0x10};
  cycles_t steps = 3;
  cpu.set_regs(status);
  memory.load_memory(program);
  /** end   - inline program */

  cpu.execute(1);

  registers_t regs = cpu.get_regs();
  memory_t mem = memory.dump_memory();

  EXPECT_EQ(regs.PC, 0x0004);
  EXPECT_EQ(cpu.get_cycles(), steps);
}

TEST_F(Opcode_JP_Test, JP_NC_A16_NoCarry_Test) {
  /** start - inline program */
  registers_t status;
  status.PC = 0x0000;
  status.c = 0;
  memory_t program = {JP_NC_A16, 0x00, 0x10};
  cycles_t steps = 4;
  cpu.set_regs(status);
  memory.load_memory(program);
  /** end   - inline program */

  cpu.execute(1);

  registers_t regs = cpu.get_regs();
  memory_t mem = memory.dump_memory();

  EXPECT_EQ(regs.PC, 0x1001);
  EXPECT_EQ(cpu.get_cycles(), steps);
}

TEST_F(Opcode_JP_Test, JP_NC_A16_Carry_Test) {
  /** start - inline program */
  registers_t status;
  status.PC = 0x0000;
  status.c = 1;
  memory_t program = {JP_NC_A16, 0x00, 0x10};
  cycles_t steps = 3;
  cpu.set_regs(status);
  memory.load_memory(program);
  /** end   - inline program */

  cpu.execute(1);

  registers_t regs = cpu.get_regs();
  memory_t mem = memory.dump_memory();

  EXPECT_EQ(regs.PC, 0x0004);
  EXPECT_EQ(cpu.get_cycles(), steps);
}

TEST_F(Opcode_JP_Test, JP_Z_A16_NoZero_Test) {
  /** start - inline program */
  registers_t status;
  status.PC = 0x0000;
  status.z = 0;
  memory_t program = {JP_Z_A16, 0x00, 0x10};
  cycles_t steps = 3;
  cpu.set_regs(status);
  memory.load_memory(program);
  /** end   - inline program */

  cpu.execute(1);

  registers_t regs = cpu.get_regs();
  memory_t mem = memory.dump_memory();

  EXPECT_EQ(regs.PC, 0x0004);
  EXPECT_EQ(cpu.get_cycles(), steps);
}

TEST_F(Opcode_JP_Test, JP_Z_A16_Zero_Test) {
  /** start - inline program */
  registers_t status;
  status.PC = 0x0000;
  status.z = 1;
  memory_t program = {JP_Z_A16, 0x00, 0x10};
  cycles_t steps = 4;
  cpu.set_regs(status);
  memory.load_memory(program);
  /** end   - inline program */

  cpu.execute(1);

  registers_t regs = cpu.get_regs();
  memory_t mem = memory.dump_memory();

  EXPECT_EQ(regs.PC, 0x1001);
  EXPECT_EQ(cpu.get_cycles(), steps);
}

TEST_F(Opcode_JP_Test, JP_C_A16_NoCarry_Test) {
  /** start - inline program */
  registers_t status;
  status.PC = 0x0000;
  status.c = 0;
  memory_t program = {JP_C_A16, 0x00, 0x10};
  cycles_t steps = 3;
  cpu.set_regs(status);
  memory.load_memory(program);
  /** end   - inline program */

  cpu.execute(1);

  registers_t regs = cpu.get_regs();
  memory_t mem = memory.dump_memory();

  EXPECT_EQ(regs.PC, 0x0004);
  EXPECT_EQ(cpu.get_cycles(), steps);
}

TEST_F(Opcode_JP_Test, JP_C_A16_Carry_Test) {
  /** start - inline program */
  registers_t status;
  status.PC = 0x0000;
  status.c = 1;
  memory_t program = {JP_C_A16, 0x00, 0x10};
  cycles_t steps = 4;
  cpu.set_regs(status);
  memory.load_memory(program);
  /** end   - inline program */

  cpu.execute(1);

  registers_t regs = cpu.get_regs();
  memory_t mem = memory.dump_memory();

  EXPECT_EQ(regs.PC, 0x1001);
  EXPECT_EQ(cpu.get_cycles(), steps);
}
