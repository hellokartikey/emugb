#include <gtest/gtest.h>

#include "fixture.hxx"

TEST_F(CPUTest, INC_A) {
    /** start - inline program */
    gb::memory program = {
        gb::INC_A,
        gb::HALT
    };
    memory.load_memory(program);
    cpu.reset();
    /** end - inline program */

    cpu.execute();

    EXPECT_EQ(cpu.A, 0x01);
    EXPECT_EQ(cpu.B, 0x00);
    EXPECT_EQ(cpu.C, 0x00);
    EXPECT_EQ(cpu.D, 0x00);
    EXPECT_EQ(cpu.E, 0x00);
    EXPECT_EQ(cpu.H, 0x00);
    EXPECT_EQ(cpu.L, 0x00);
    EXPECT_EQ(cpu.PC, 0x0002);
}
