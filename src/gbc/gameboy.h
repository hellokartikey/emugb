#ifndef EMUGB_GAMEBOY_H
#define EMUGB_GAMEBOY_H

#include "cpu.h"

namespace gbc {
class Gameboy {
 public:
  Gameboy();
  ~Gameboy();

  auto init() -> void;

 private:
  CPU cpu;
};
}  // namespace gbc

#endif
