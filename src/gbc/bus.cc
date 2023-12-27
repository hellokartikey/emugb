#include "bus.h"

namespace gbc {
auto Bus::data() -> byte { return data_bus; }

auto Bus::data(byte data) -> void {
  data_bus = data;
  data_signal(data_bus);
}

auto Bus::addr() -> word { return addr_bus; }

auto Bus::addr(word addr) -> void {
  addr_bus = addr;
  addr_signal(addr_bus);
}
}  // namespace gbc
