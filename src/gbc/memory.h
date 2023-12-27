#ifndef EMUGB_MEMORY_H
#define EMUGB_MEMORY_H

#include <hk/signals.h>

#include "common.h"

namespace gbc {
class Memory {
 public:
  Memory();
  ~Memory();

  auto operator[](word addr) -> byte&;

 public:  // Signals and Slots
  // Read from memory
  hk::signals::Signal<byte> write_data_to_bus;
  auto read_addr_from_bus(word addr) -> void;

  // Write to memory
  auto write_data_from_bus(word addr, byte data) -> void;

 private:  // Members
  memory_block<0xffff> memory;
};
}  // namespace gbc

#endif
