#include <gtest/gtest.h>

#include "opcode.h"

using namespace gbc;

TEST(OpcodeTest, Row0) {
    EXPECT_EQ(NOP      , 0x00);
    EXPECT_EQ(LD_BC_D16, 0x01);
    EXPECT_EQ(LD_ABC_A , 0x02);
    EXPECT_EQ(INC_BC   , 0x03);
    EXPECT_EQ(INC_B    , 0x04);
    EXPECT_EQ(DEC_B    , 0x05);
    EXPECT_EQ(LD_B_D8  , 0x06);
    EXPECT_EQ(RLCA     , 0x07);
    EXPECT_EQ(LD_A16_SP, 0x08);
    EXPECT_EQ(ADD_HL_BC, 0x09);
    EXPECT_EQ(LD_A_ABC , 0x0a);
    EXPECT_EQ(DEC_BC   , 0x0b);
    EXPECT_EQ(INC_C    , 0x0c);
    EXPECT_EQ(DEC_C    , 0x0d);
    EXPECT_EQ(LD_C_D8  , 0x0e);
    EXPECT_EQ(RRCA     , 0x0f);
}
