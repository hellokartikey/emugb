#include "types.h"

namespace gbc {
bool operator==(const registers_t& lhs, const registers_t& rhs) {
  if ((lhs.AF != rhs.AF) || (lhs.BC != rhs.BC) || (lhs.DE != rhs.DE) ||
      (lhs.HL != rhs.HL) || (lhs.SP != rhs.SP) || (lhs.PC != rhs.PC)) {
    return false;
  }

  return true;
}

bool operator!=(const registers_t& lhs, const registers_t& rhs) {
  return !(lhs == rhs);
}

bool bit(const byte& r8, const std::size_t bit) { return r8 & (0x01 << bit); }

void bit(byte& r8, const std::size_t bit, bool value) {
  if (value)
    r8 = r8 | (0x01 << bit);
  else
    r8 = r8 & (0xff ^ (0x01 << bit));
}
};  // namespace gbc