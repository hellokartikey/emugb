#include <gtest/gtest.h>

#include "fixture.hxx"

#include <array>

TEST_F(CPUTest, LD_B_D8) {
    /** start - inline program */
    gb::memory program = {
        gb::LD_B_D8, 0x64,
        gb::HALT
    };
    memory.load_memory(program);
    cpu.reset();
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

TEST_F(CPUTest, LD_C_D8) {
    /** start - inline program */
    gb::memory program = {
        gb::LD_C_D8, 0x64,
        gb::HALT
    };
    memory.load_memory(program);
    cpu.reset();
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

TEST_F(CPUTest, LD_D_D8) {
    /** start - inline program */
    gb::memory program = {
        gb::LD_D_D8, 0x64,
        gb::HALT
    };
    memory.load_memory(program);
    cpu.reset();
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

TEST_F(CPUTest, LD_E_D8) {
    /** start - inline program */
    gb::memory program = {
        gb::LD_E_D8, 0x64,
        gb::HALT
    };
    memory.load_memory(program);
    cpu.reset();
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
