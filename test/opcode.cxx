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

TEST(OpcodeTest, LD_E_Test) {
    EXPECT_EQ(LD_E_B,   0x58);
    EXPECT_EQ(LD_E_C,   0x59);
    EXPECT_EQ(LD_E_D,   0x5A);
    EXPECT_EQ(LD_E_E,   0x5B);
    EXPECT_EQ(LD_E_H,   0x5C);
    EXPECT_EQ(LD_E_L,   0x5D);
    EXPECT_EQ(LD_E_AHL, 0x5E);
    EXPECT_EQ(LD_E_A,   0x5F);
}

TEST(OpcodeTest, LD_H_Test) {
    EXPECT_EQ(LD_H_B,   0x60);
    EXPECT_EQ(LD_H_C,   0x61);
    EXPECT_EQ(LD_H_D,   0x62);
    EXPECT_EQ(LD_H_E,   0x63);
    EXPECT_EQ(LD_H_H,   0x64);
    EXPECT_EQ(LD_H_L,   0x65);
    EXPECT_EQ(LD_H_AHL, 0x66);
    EXPECT_EQ(LD_H_A,   0x67);
}

TEST(OpcodeTest, LD_L_Test) {
    EXPECT_EQ(LD_L_B,   0x68);
    EXPECT_EQ(LD_L_C,   0x69);
    EXPECT_EQ(LD_L_D,   0x6A);
    EXPECT_EQ(LD_L_E,   0x6B);
    EXPECT_EQ(LD_L_H,   0x6C);
    EXPECT_EQ(LD_L_L,   0x6D);
    EXPECT_EQ(LD_L_AHL, 0x6E);
    EXPECT_EQ(LD_L_A,   0x6F);
}

TEST(OpcodeTest, LD_AR16_Test) {
    EXPECT_EQ(LD_AHL_B,  0x70);
    EXPECT_EQ(LD_AHL_C,  0x71);
    EXPECT_EQ(LD_AHL_D,  0x72);
    EXPECT_EQ(LD_AHL_E,  0x73);
    EXPECT_EQ(LD_AHL_H,  0x74);
    EXPECT_EQ(LD_AHL_L,  0x75);
    EXPECT_EQ(LD_AHL_A,  0x77);
    EXPECT_EQ(LD_ABC_A,  0x02);
    EXPECT_EQ(LD_ADE_A,  0x12);
    EXPECT_EQ(LD_AHLP_A, 0x22);
    EXPECT_EQ(LD_AHLM_A, 0x32);
}

TEST(OpcodeTest, LD_A_Test) {
    EXPECT_EQ(LD_A_B,    0x78);
    EXPECT_EQ(LD_A_C,    0x79);
    EXPECT_EQ(LD_A_D,    0x7A);
    EXPECT_EQ(LD_A_E,    0x7B);
    EXPECT_EQ(LD_A_H,    0x7C);
    EXPECT_EQ(LD_A_L,    0x7D);
    EXPECT_EQ(LD_A_AHL,  0x7E);
    EXPECT_EQ(LD_A_A,    0x7F);
    EXPECT_EQ(LD_A_ABC,  0x0A);
    EXPECT_EQ(LD_A_ADE,  0x1A);
    EXPECT_EQ(LD_A_AHLP, 0x2A);
    EXPECT_EQ(LD_A_AHLM, 0x3A);
}
