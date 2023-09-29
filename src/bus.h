#ifndef EMUGB_BUS_H
#define EMUGB_BUS_H

#include "types.h"

namespace gbc {
// Forward declaration
class Bus;

class CPU;
class Memory;

class Bus {
 public:
  Bus();

  // Read memory
  byte read(word addr);

  // Write memory
  void write(word addr, byte data);

 public:  // Connect components
  void connect_cpu(CPU& cpu);
  void connect_memory(Memory& memory);

 private:
  CPU* cpu_;
  Memory* mem_;
};
}  // namespace gbc

#endif
