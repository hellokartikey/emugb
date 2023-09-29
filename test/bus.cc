#include "bus.h"

#include <gtest/gtest.h>

#include "bus.h"
#include "memory.h"

class BusTests : public testing::Test {
 protected:
  gbc::Bus bus;
  gbc::Memory mem;

  BusTests() { mem.connect_bus(bus); }
};

TEST_F(BusTests, ReadTest) {
  mem[0x1000] = 0x64;

  EXPECT_EQ(bus.read(0x1000), 0x64);
}

TEST_F(BusTests, WriteTest) {
  bus.write(0x1000, 0x64);

  EXPECT_EQ(mem[0x1000], 0x64);
}
