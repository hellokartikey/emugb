#include <gtest/gtest.h>

#include "bus.h"
#include "cpu.h"
#include "memory.h"

using namespace gbc;

class CPUOpcodeTests : public testing::Test {
 protected:
  CPU cpu;
  Memory mem;
  Bus bus;

  CPUOpcodeTests() {
    cpu.connect_bus(bus);
    mem.connect_bus(bus);

    cpu.reset();
  }
};
