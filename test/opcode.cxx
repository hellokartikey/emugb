#include <gtest/gtest.h>

#include "fixture.hxx"

using namespace gb;

TEST(OpcodeTest, MiscTest) {
    EXPECT_EQ(NOP, 0x00);
}

TEST(OpcodeTest, LD_R16_D16_Test) {
    EXPECT_EQ(LD_BC_D16, 0x01);
    EXPECT_EQ(LD_DE_D16, 0x11);
    EXPECT_EQ(LD_HL_D16, 0x21);
    EXPECT_EQ(LD_SP_D16, 0x31);
}

TEST(OpcodeTest, LD_R8_D8_Test) {
    EXPECT_EQ(LD_B_D8, 0x06);
    EXPECT_EQ(LD_C_D8, 0x0E);
    EXPECT_EQ(LD_D_D8, 0x16);
    EXPECT_EQ(LD_E_D8, 0x1E);
    EXPECT_EQ(LD_H_D8, 0x26);
    EXPECT_EQ(LD_L_D8, 0x2E);
    EXPECT_EQ(LD_AHL_D8, 0x36);
    EXPECT_EQ(LD_A_D8, 0x3E);
}
