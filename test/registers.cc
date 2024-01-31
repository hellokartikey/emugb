#include "registers.h"

#include <gtest/gtest.h>

class RegistersTests : public testing::Test {
 protected:
  gbc::R16 reg;

  RegistersTests() {}
};

TEST_F(RegistersTests, ConstructByWord) {
  reg = gbc::R16(0x1234);

  EXPECT_EQ(reg, 0x1234);
}

TEST_F(RegistersTests, ConstructByBytes) {
  reg = gbc::R16(0x12, 0x34);

  EXPECT_EQ(reg, 0x1234);
}

TEST_F(RegistersTests, ConstructDefault) {
  reg = gbc::R16();

  EXPECT_EQ(reg, 0x0000);
}

TEST_F(RegistersTests, GetBytes) {
  reg = gbc::R16(0x1024);

  EXPECT_EQ(reg.lo(), 0x24);
  EXPECT_EQ(reg.up(), 0x10);
}

TEST_F(RegistersTests, IncrementOperators) {
  reg = gbc::R16(0x1000);

  reg++;
  EXPECT_EQ(reg--, 0x1001);
  EXPECT_EQ(reg++, 0x1000);
  EXPECT_EQ(--reg, 0x1000);
  EXPECT_EQ(++reg, 0x1001);
}

TEST_F(RegistersTests, Indexing) {
  reg = gbc::R16(0xabcd);

  for (auto idx = std::size_t{0}; idx < 16; ++idx) {
    EXPECT_EQ(reg[idx], bool(0xabcd & (1 << idx)));
  }
}

TEST_F(RegistersTests, Addition) {
  reg = gbc::R16(0x1234) + gbc::R16(0xabcd);

  EXPECT_EQ(reg, 0x1234 + 0xabcd);
}
