#include <gtest/gtest.h>

#include "cpu/cpu.hxx"

TEST(OpcodeTest, MiscOpcodeTest) {
    EXPECT_EQ(gb::NOP, 0x00);
    EXPECT_EQ(gb::STOP, 0x10);
    EXPECT_EQ(gb::HALT, 0x76);
    EXPECT_EQ(gb::PREFIX, 0xCB);
    EXPECT_EQ(gb::DI, 0xF3);
    EXPECT_EQ(gb::EI, 0xFB);
}

TEST(OpcodeTest, JumpOpcodeTest) {
    EXPECT_EQ(gb::JR_R8,     0x18);
    EXPECT_EQ(gb::JR_NZ_R8,  0x20);
    EXPECT_EQ(gb::JR_Z_R8,   0x28);
    EXPECT_EQ(gb::JR_NC_R8,  0x30);
    EXPECT_EQ(gb::JR_C_R8,   0x38);
    EXPECT_EQ(gb::JP_NZ_A16, 0xC2);
    EXPECT_EQ(gb::JP_A16,    0xC3);
    EXPECT_EQ(gb::JP_Z_A16,  0xCA);
    EXPECT_EQ(gb::JP_NC_A16, 0xD2);
    EXPECT_EQ(gb::JP_C_A16,  0xDA);
    EXPECT_EQ(gb::JP_HL,     0xE9);
}

TEST(OpcodeTest, CallOpcodeTest) {
    EXPECT_EQ(gb::CALL_NZ_A16, 0xC4);
    EXPECT_EQ(gb::CALL_Z_A16,  0xCC);
    EXPECT_EQ(gb::CALL_A16,    0xCD);
    EXPECT_EQ(gb::CALL_NC_A16, 0xD4);
    EXPECT_EQ(gb::CALL_C_A16,  0xDC);
}

TEST(OpcodeTest, ReturnOpcodeTest) {
    EXPECT_EQ(gb::RET_NZ, 0xC0);
    EXPECT_EQ(gb::RET_Z,  0xC8);
    EXPECT_EQ(gb::RET,    0xC9);
    EXPECT_EQ(gb::RET_NC, 0xD0);
    EXPECT_EQ(gb::RET_C,  0xD8);
    EXPECT_EQ(gb::RETI,   0xD9);
}

TEST(OpcodeTest, ResetOpcodeTest) {
    EXPECT_EQ(gb::RST_00, 0xC7);
    EXPECT_EQ(gb::RST_08, 0xCF);
    EXPECT_EQ(gb::RST_10, 0xD7);
    EXPECT_EQ(gb::RST_18, 0xDF);
    EXPECT_EQ(gb::RST_20, 0xE7);
    EXPECT_EQ(gb::RST_28, 0xEF);
    EXPECT_EQ(gb::RST_30, 0xF7);
    EXPECT_EQ(gb::RST_38, 0xFF);
}
