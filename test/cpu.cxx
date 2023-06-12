#include <gtest/gtest.h>

#include "cpu/cpu.hxx"
#include "cpu/bus.hxx"

class CPUTest : public testing::Test {
protected:
    gb::Bus bus;
    gb::Memory memory;
    gb::CPU cpu;

    CPUTest() : memory(bus), cpu(bus, memory) {}
};

TEST_F(CPUTest, InitTest) {
    EXPECT_EQ(cpu.AF, 0x00);
    EXPECT_EQ(cpu.BC, 0x00);
    EXPECT_EQ(cpu.DE, 0x00);
    EXPECT_EQ(cpu.HL, 0x00);
    EXPECT_EQ(cpu.SP, 0x00);
    EXPECT_EQ(cpu.PC, 0x00);
}
