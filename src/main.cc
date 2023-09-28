#include <fmt/core.h>

#include <iostream>

#include "bus.h"
#include "cpu.h"
#include "memory.h"
#include "opcode.h"
#include "types.h"

using namespace gbc;

int main() {
  CPU cpu;
  Memory memory;
  Bus bus;

  cpu.connect_bus(bus);
  memory.connect_bus(bus);

  program_t test_prog = {NOP, NOP, LD_BC_D16};

  memory.load_program(test_prog);

  fmt::print("Begin\n");

  cpu.execute(0x0f);

  return 0;
}
