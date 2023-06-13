#include <gtest/gtest.h>

#include <cstdlib>

#include "cpu/bus.hxx"

class BusTest : public testing::Test {
protected:
    gb::Bus bus;
};

TEST_F(BusTest, InitTest) {
    EXPECT_EQ(bus.read_addr(), 0x0000);
    EXPECT_EQ(bus.read_data(), 0x00);
    EXPECT_EQ(bus.read_signal(), true);
}

TEST_F(BusTest, SetWrite) {
    bus.set_write();
    EXPECT_EQ(bus.read_signal(), false);
}

TEST_F(BusTest, SetRead) {
    bus.set_read();
    EXPECT_EQ(bus.read_signal(), true);
}

TEST_F(BusTest, ReadWriteAddrTest) {
    for (int count = 0; count < 100; count++) {
        gb::word testcase = std::rand() % gb::max_word;
        bus.write_addr(testcase);
        EXPECT_EQ(bus.read_addr(), testcase);
    }
}

TEST_F(BusTest, ReadWriteDataTest) {
    for (int count = 0; count < 100; count++) {
        gb::byte testcase = std::rand() % gb::max_byte;
        bus.write_data(testcase);
        EXPECT_EQ(bus.read_data(), testcase);
    }
}
