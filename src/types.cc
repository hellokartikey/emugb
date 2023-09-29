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
};  // namespace gbc