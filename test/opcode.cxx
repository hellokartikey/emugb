#include <gtest/gtest.h>

#include "cpu/cpu.hxx"

TEST(OPCODE, LD_R8_D8_OPCODES) {
    EXPECT_EQ(gb::LD_B_D8, 0x06);
    EXPECT_EQ(gb::LD_C_D8, 0x0E);
    EXPECT_EQ(gb::LD_D_D8, 0x16);
    EXPECT_EQ(gb::LD_E_D8, 0x1E);
    EXPECT_EQ(gb::LD_H_D8, 0x26);
    EXPECT_EQ(gb::LD_L_D8, 0x2E);
}

TEST(OPCODE, MISC_OPCODES) {
    EXPECT_EQ(gb::NOP, 0x00);
    EXPECT_EQ(gb::HALT, 0x76);
}
