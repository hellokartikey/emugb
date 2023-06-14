#include <gtest/gtest.h>

#include "cpu/cpu.hxx"
#include "cpu/memory.hxx"

class LD_R8_R8 : public testing::Test {
protected:
    gb::Bus bus;
    gb::Memory memory;
    gb::CPU cpu;

    LD_R8_R8() : memory(bus), cpu(bus, memory) {}
};

TEST_F(LD_R8_R8, LD_A_A) {
    /** start - inline program */
    gb::memory program = {
        gb::LD_B_D8, 0x64,
        gb::LD_A_B,
        gb::LD_A_A,
        gb::HALT
    };
    memory.load_memory(program);
    cpu.reset();
    /** end - inline program */

    cpu.execute();

    EXPECT_EQ(cpu.A, 0x64);
    EXPECT_EQ(cpu.B, 0x64);
    EXPECT_EQ(cpu.C, 0x00);
    EXPECT_EQ(cpu.D, 0x00);
    EXPECT_EQ(cpu.E, 0x00);
    EXPECT_EQ(cpu.H, 0x00);
    EXPECT_EQ(cpu.L, 0x00);
    EXPECT_EQ(cpu.PC, 0x0005);
}

TEST_F(LD_R8_R8, LD_A_B) {
    /** start - inline program */
    gb::memory program = {
        gb::LD_B_D8, 0x64,
        gb::LD_A_B,
        gb::HALT
    };
    memory.load_memory(program);
    cpu.reset();
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
