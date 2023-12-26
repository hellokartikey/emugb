#ifndef EMUGB_CPU_H
#define EMUGB_CPU_H

#include <hk/signals/signals.h>

#include "common.h"
#include "registers.h"

namespace gbc {
class CPU {
 public:
  CPU();
  ~CPU();

 public: // Signals and Slots
  hk::signals::Signal<word> write_addr_to_bus;
  auto read_data_from_bus(byte data) -> void;

 private: // Members
  Registers regs;

  byte fetch;
};
}  // namespace gbc

#endif
