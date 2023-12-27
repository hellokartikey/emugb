#include <fmt/core.h>

#include <iostream>

#include "gbc/gameboy.h"

auto main() -> int {
  auto game = gbc::Gameboy{};

  game.test();

  return 0;
}
