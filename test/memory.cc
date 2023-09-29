#include "memory.h"

#include <gtest/gtest.h>

#include "bus.h"

class MemoryTests : public testing::Test {
 protected:
  gbc::Bus bus;
  gbc::Memory mem;

  MemoryTests() { mem.connect_bus(bus); }
};

TEST_F(MemoryTests, BusConnectedTest) { EXPECT_TRUE(mem.is_bus_connected()); }
