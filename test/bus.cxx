#include <gtest/gtest.h>

#include "fixture.hxx"

TEST_F(BusTest, InitTest) {
  EXPECT_EQ(bus.read_addr(), 0x0000);
  EXPECT_EQ(bus.read_data(), 0x00);
  EXPECT_EQ(bus.read_signal(), true);
}

TEST_F(BusTest, SetWrite) {
  bus.set_write();
  EXPECT_FALSE(bus.read_signal());
}

TEST_F(BusTest, SetRead) {
  bus.set_read();
  EXPECT_TRUE(bus.read_signal());
}

TEST_F(BusTest, ReadWriteAddrTest) {
  gb::word testcase = gb::rand_word();
  bus.write_addr(testcase);
  EXPECT_EQ(bus.read_addr(), testcase);
}

TEST_F(BusTest, ReadWriteDataTest) {
  gb::byte testcase = gb::rand_byte();
  bus.write_data(testcase);
  EXPECT_EQ(bus.read_data(), testcase);
}
