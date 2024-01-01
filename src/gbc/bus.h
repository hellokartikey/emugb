#ifndef EMUGB_BUS_H
#define EMUGB_BUS_H

#include <hk/signal.h>

#include "common.h"

namespace gbc {
class Bus {
 public:
  Bus() = default;
  ~Bus() = default;

 public:  // Signals and Slots
  hk::signals::Signal<word> addr_signal;
  hk::signals::Signal<byte> data_signal;

 public:  // Reads and Writes
  auto data() -> byte;
  auto data(byte data) -> void;

  auto addr() -> word;
  auto addr(word addr) -> void;

 private:  // Members
  byte data_bus;
  word addr_bus;
};
}  // namespace gbc

#endif
