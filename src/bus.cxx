#include "bus.hxx"

namespace gb {
Bus::Bus() {
  data = 0;
  addr = 0;
  read = true;
}

bool Bus::read_signal() { return read; }

void Bus::set_write() { read = false; }

void Bus::set_read() { read = true; }

void Bus::write_addr(word addr) { this->addr = addr; }

word Bus::read_addr() { return addr; }

void Bus::write_data(byte data) { this->data = data; }

byte Bus::read_data() { return data; }
}  // namespace gb
