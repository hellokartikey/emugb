#ifndef EMUGB_BUS_H
#define EMUGB_BUS_H

#include "cpu.h"
#include "memory.h"
#include "types.h"

namespace gbc {
class Bus {
 public:
  Bus();

  // Read memory
  byte read(word addr);

  // Write memory
  void write(word addr, byte data);

 private:
  CPU cpu;
  Memory memory;
};
}  // namespace gbc

#endif
