#include <gtest/gtest.h>

#include "bus.h"
#include "cpu.h"
#include "memory.h"

class BusTestFixture : public testing::Test {
 protected:
  gbc::Bus bus;
};
