#include <gtest/gtest.h>

#include "cpu/cpu.hxx"

TEST(OPCODE, LD_X_D8_OPCODES) {
    EXPECT_EQ(LD_B_D8, 0x06);
    EXPECT_EQ(LD_C_D8, 0x0E);
    EXPECT_EQ(LD_D_D8, 0x16);
    EXPECT_EQ(LD_E_D8, 0x1E);
    EXPECT_EQ(LD_H_D8, 0x26);
    EXPECT_EQ(LD_L_D8, 0x2E);
}

TEST(OPCODE, MISC_OPCODES) {
    EXPECT_EQ(NOP, 0x00);
    EXPECT_EQ(HALT, 0x76);
}
