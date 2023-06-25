#include <gtest/gtest.h>

#include "fixture.hxx"

using namespace gb;

TEST(OpcodeTest, MiscTest) {
    EXPECT_EQ(NOP,  0x00);
    EXPECT_EQ(STOP, 0x10);
}

TEST(OpcodeTest, LD_R16_D16_Test) {
    EXPECT_EQ(LD_BC_D16, 0x01);
    EXPECT_EQ(LD_DE_D16, 0x11);
    EXPECT_EQ(LD_HL_D16, 0x21);
    EXPECT_EQ(LD_SP_D16, 0x31);
}

TEST(OpcodeTest, LD_X_D8_Test) {
    EXPECT_EQ(LD_B_D8,   0x06);
    EXPECT_EQ(LD_C_D8,   0x0E);
    EXPECT_EQ(LD_D_D8,   0x16);
    EXPECT_EQ(LD_E_D8,   0x1E);
    EXPECT_EQ(LD_H_D8,   0x26);
    EXPECT_EQ(LD_L_D8,   0x2E);
    EXPECT_EQ(LD_AHL_D8, 0x36);
    EXPECT_EQ(LD_A_D8,   0x3E);
}

TEST(OpcodeTest, LD_B_Test) {
    EXPECT_EQ(LD_B_B,   0x40);
    EXPECT_EQ(LD_B_C,   0x41);
    EXPECT_EQ(LD_B_D,   0x42);
    EXPECT_EQ(LD_B_E,   0x43);
    EXPECT_EQ(LD_B_H,   0x44);
    EXPECT_EQ(LD_B_L,   0x45);
    EXPECT_EQ(LD_B_AHL, 0x46);
    EXPECT_EQ(LD_B_A,   0x47);
}

TEST(OpcodeTest, LD_C_Test) {
    EXPECT_EQ(LD_C_B,   0x48);
    EXPECT_EQ(LD_C_C,   0x49);
    EXPECT_EQ(LD_C_D,   0x4A);
    EXPECT_EQ(LD_C_E,   0x4B);
    EXPECT_EQ(LD_C_H,   0x4C);
    EXPECT_EQ(LD_C_L,   0x4D);
    EXPECT_EQ(LD_C_AHL, 0x4E);
    EXPECT_EQ(LD_C_A,   0x4F);
}

TEST(OpcodeTest, LD_D_Test) {
    EXPECT_EQ(LD_D_B,   0x50);
    EXPECT_EQ(LD_D_C,   0x51);
    EXPECT_EQ(LD_D_D,   0x52);
    EXPECT_EQ(LD_D_E,   0x53);
    EXPECT_EQ(LD_D_H,   0x54);
    EXPECT_EQ(LD_D_L,   0x55);
    EXPECT_EQ(LD_D_AHL, 0x56);
    EXPECT_EQ(LD_D_A,   0x57);
}
