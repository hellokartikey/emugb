#include <gtest/gtest.h>

#include "fixture.hxx"

TEST_F(CPUTest, InitTest) {
    gb::registers_t out {
        0x11B0,
        0x0013,
        0x00D8,
        0x014D,
        0xFFFE,
        0x0000
    };

    EXPECT_TRUE(gb::regs_iseq(cpu.get_regs(), out));

    EXPECT_EQ(cpu.get_current(), 0x00);
    EXPECT_EQ(cpu.get_cycles(), 0x00);
    // TODO Memory
}

TEST_F(CPUTest, ResetTest) {
    gb::registers_t out = {
        0x0000,
        0x0000,
        0x0000,
        0x0000,
        0x0000,
        0x0000
    };

    cpu.reset();

    EXPECT_TRUE(gb::regs_iseq(cpu.get_regs(), out));
    EXPECT_EQ(cpu.get_current(), 0x00);
    EXPECT_EQ(cpu.get_cycles(), 0x00);
}

TEST_F(CPUTest, MemoryInterfaceTest) {
    gb::word addr = gb::rand_word();
    gb::byte data = gb::rand_byte();
    cpu.write_memory(addr, data);

    EXPECT_EQ(cpu.get_cycles(), 0x0001);

    cpu.read_memory(addr);

    EXPECT_EQ(cpu.get_current(), data);
    EXPECT_EQ(cpu.get_cycles(), 0x0002);
}

TEST_F(CPUTest, SteppedExecution) {
    gb::cycles_t test_steps = 10;

    cpu.execute(test_steps);

    EXPECT_EQ(cpu.get_cycles(), test_steps);
}
