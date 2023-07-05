#pragma once

#include "common.hxx"

namespace gb {
class Bus {
  byte data;
  word addr;

  bool read;

 public:
  Bus();

  bool read_signal();

  void set_write();
  void set_read();

  void write_addr(word addr);
  word read_addr();

  void write_data(byte data);
  byte read_data();
};
}  // namespace gb
