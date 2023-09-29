#include "types.h"

namespace gbc {
// registers_t::registers_t(word AF, word BC, word DE, word HL, word SP, word
// PC,

//                          byte A, byte B, byte C, byte D, byte E, byte H, byte
//                          L,

//                          bool c, bool h, bool n, bool z) {
//   this->AF = AF;
//   this->BC = BC;
//   this->DE = DE;
//   this->HL = HL;
//   this->SP = SP;
//   this->PC = PC;

//   this->A = A;
//   this->B = B;
//   this->C = C;
//   this->D = D;
//   this->E = E;
//   this->H = H;
//   this->L = L;

//   this->c = c;
//   this->h = h;
//   this->n = n;
//   this->z = z;
// }

bool operator==(const registers_t& lhs, const registers_t& rhs) {
  if ((lhs.AF != rhs.AF) || (lhs.BC != rhs.BC) || (lhs.DE != rhs.BC) ||
      (lhs.HL != rhs.HL) || (lhs.SP != rhs.SP) || (lhs.PC != rhs.PC)) {
    return false;
  }

  return true;
}

bool operator!=(const registers_t& lhs, const registers_t& rhs) {
  return !(lhs == rhs);
}
};  // namespace gbc