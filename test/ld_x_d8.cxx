#include <gtest/gtest.h>

#include "cpu/cpu.hxx"
#include "cpu/memory.hxx"

#include <array>

class LD_R8_D8 : public testing::Test {
protected:
    gb::Bus bus;
    gb::Memory memory;
    gb::CPU cpu;

    LD_R8_D8() : memory(bus), cpu(bus, memory) {}
};

TEST_F(LD_R8_D8, LD_B_D8) {
    /** start - inline program */
    constexpr gb::word size = 0x0003;
    gb::memory program = {
        gb::LD_B_D8, 0x64,
        gb::HALT
    };
    memory.load_memory(program);
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

TEST_F(LD_R8_D8, LD_C_D8) {
    /** start - inline program */
    constexpr gb::word size = 0x0003;
    gb::memory program = {
        gb::LD_C_D8, 0x64,
        gb::HALT
    };
    memory.load_memory(program);
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

TEST_F(LD_R8_D8, LD_D_D8) {
    /** start - inline program */
    constexpr gb::word size = 0x0003;
    gb::memory program = {
        gb::LD_D_D8, 0x64,
        gb::HALT
    };
    memory.load_memory(program);
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

TEST_F(LD_R8_D8, LD_E_D8) {
    /** start - inline program */
    constexpr gb::word size = 0x0003;
    gb::memory program = {
        gb::LD_E_D8, 0x64,
        gb::HALT
    };
    memory.load_memory(program);
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
