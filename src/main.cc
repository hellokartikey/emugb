#include <fmt/core.h>

#include <iostream>

#include "types.h"

int main() {
  gbc::registers_t regs;

  regs.BC = 0x0000;

  regs.C = 0xff;
  fmt::print("{:x}\n", regs.BC);

  fmt::print("{}\n", sizeof(regs));
  return 0;
}
