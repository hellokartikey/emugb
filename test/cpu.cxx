#include <gtest/gtest.h>

#include "fixture.hxx"

TEST_F(CPUTest, InitTest) {
    EXPECT_EQ(cpu.AF, 0x11B0);
    EXPECT_EQ(cpu.BC, 0x0013);
    EXPECT_EQ(cpu.DE, 0x00D8);
    EXPECT_EQ(cpu.HL, 0x014D);
    EXPECT_EQ(cpu.SP, 0xFFFE);
    EXPECT_EQ(cpu.PC, 0x0100);
    // TODO Memory
}

TEST_F(CPUTest, ResetTest) {
    cpu.reset();
    EXPECT_EQ(cpu.AF, 0x0000);
    EXPECT_EQ(cpu.BC, 0x0000);
    EXPECT_EQ(cpu.DE, 0x0000);
    EXPECT_EQ(cpu.HL, 0x0000);
    EXPECT_EQ(cpu.SP, 0x0000);
    EXPECT_EQ(cpu.PC, 0x0000);
}

TEST_F(CPUTest, MemoryInterfaceTest) {
    gb::word addr = gb::rand_word();
    gb::byte data = gb::rand_byte();
    cpu.write_memory(addr, data);
    EXPECT_EQ(cpu.cycles, 0x0001);
    cpu.read_memory(addr);
    EXPECT_EQ(cpu.IR, data);
    EXPECT_EQ(cpu.cycles, 0x0002);
}
