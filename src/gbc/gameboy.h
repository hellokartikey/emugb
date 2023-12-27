#ifndef EMUGB_GAMEBOY_H
#define EMUGB_GAMEBOY_H

#include "bus.h"
#include "cpu.h"
#include "memory.h"

namespace gbc {
class Gameboy {
 public:
  Gameboy();
  ~Gameboy();

  auto init() -> void;

 public:  // (tmp) Testing function
  auto test() -> void;

 private:
  CPU cpu;
  Memory memory;
  Bus bus;
};
}  // namespace gbc

#endif
