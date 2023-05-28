#include <gtest/gtest.h>

#include "cpu/cpu.hxx"

class LD_X_D8 : public testing::Test {
protected:
    Memory memory;
    CPU cpu;

    LD_X_D8() : cpu(memory) {}
};

TEST_F(LD_X_D8, LD_B_D8) {
    /** start - inline program */
    memory.write(0x0000, LD_B_D8);
    memory.write(0x0001, 0x64);
    memory.write(0x0002, HALT);
    /** end - inline program */

    cpu.execute();

    EXPECT_EQ(cpu.A, 0x00);
    EXPECT_EQ(cpu.B, 0x64);
    EXPECT_EQ(cpu.C, 0x00);
    EXPECT_EQ(cpu.D, 0x00);
    EXPECT_EQ(cpu.E, 0x00);
    EXPECT_EQ(cpu.H, 0x00);
    EXPECT_EQ(cpu.L, 0x00);
    EXPECT_EQ(cpu.PC, 0x0003);
}

TEST_F(LD_X_D8, LD_C_D8) {
    /** start - inline program */
    memory.write(0x0000, LD_C_D8);
    memory.write(0x0001, 0x64);
    memory.write(0x0002, HALT);
    /** end - inline program */

    cpu.execute();

    EXPECT_EQ(cpu.A, 0x00);
    EXPECT_EQ(cpu.B, 0x00);
    EXPECT_EQ(cpu.C, 0x64);
    EXPECT_EQ(cpu.D, 0x00);
    EXPECT_EQ(cpu.E, 0x00);
    EXPECT_EQ(cpu.H, 0x00);
    EXPECT_EQ(cpu.L, 0x00);
    EXPECT_EQ(cpu.PC, 0x0003);
}

TEST_F(LD_X_D8, LD_D_D8) {
    /** start - inline program */
    memory.write(0x0000, LD_D_D8);
    memory.write(0x0001, 0x64);
    memory.write(0x0002, HALT);
    /** end - inline program */

    cpu.execute();

    EXPECT_EQ(cpu.A, 0x00);
    EXPECT_EQ(cpu.B, 0x00);
    EXPECT_EQ(cpu.C, 0x00);
    EXPECT_EQ(cpu.D, 0x64);
    EXPECT_EQ(cpu.E, 0x00);
    EXPECT_EQ(cpu.H, 0x00);
    EXPECT_EQ(cpu.L, 0x00);
    EXPECT_EQ(cpu.PC, 0x0003);
}

TEST_F(LD_X_D8, LD_E_D8) {
    /** start - inline program */
    memory.write(0x0000, LD_E_D8);
    memory.write(0x0001, 0x64);
    memory.write(0x0002, HALT);
    /** end - inline program */

    cpu.execute();

    EXPECT_EQ(cpu.A, 0x00);
    EXPECT_EQ(cpu.B, 0x00);
    EXPECT_EQ(cpu.C, 0x00);
    EXPECT_EQ(cpu.D, 0x00);
    EXPECT_EQ(cpu.E, 0x64);
    EXPECT_EQ(cpu.H, 0x00);
    EXPECT_EQ(cpu.L, 0x00);
    EXPECT_EQ(cpu.PC, 0x0003);
}
