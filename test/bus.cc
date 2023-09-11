#include <gtest/gtest.h>

#include "fixture.h"

TEST_F(BusTestFixture, InitTest) {
  EXPECT_EQ(0, 0x00);
}
