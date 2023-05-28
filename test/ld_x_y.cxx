#include <gtest/gtest.h>

#include "cpu/cpu.hxx"

class LD_X_Y : public testing::Test {
protected:
    Memory memory;
    CPU cpu;

    LD_X_Y() : cpu(memory) {}
};

TEST_F(LD_X_Y, LD_A_A) {
    /** start - inline program */
    memory.write(0x0000, LD_B_D8);
    memory.write(0x0001, 0x64);
    memory.write(0x0002, LD_A_B);
    memory.write(0x0003, HALT);
    /** end - inline program */

    cpu.execute();

    EXPECT_EQ(cpu.A, 0x64);
    EXPECT_EQ(cpu.B, 0x64);
    EXPECT_EQ(cpu.C, 0x00);
    EXPECT_EQ(cpu.D, 0x00);
    EXPECT_EQ(cpu.E, 0x00);
    EXPECT_EQ(cpu.H, 0x00);
    EXPECT_EQ(cpu.L, 0x00);
    EXPECT_EQ(cpu.PC, 0x0004);
}
