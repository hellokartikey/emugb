#ifndef EMUGB_OPCODE_H
#define EMUGB_OPCODE_H

#include <cstdint>

#include "types.h"

namespace gbc {
/**
 * R8   :   8 Bit Register
 * R16  :   16 Bit Register
 * D8   :   8 Bit Data
 * D16  :   16 Bit Data
 * A8   :   8 Bit Address
 * A16  :   16 Bit Address
 * AR16 :   Register Address
 *
 * NZ   :   Not Zero
 * Z    :   Zero
 * NC   :   No Carry
 * C    :   Carry
 */
enum opcode : byte {
  // Row 0
  NOP = 0x00,
  LD_BC_D16 = 0x01,
  LD_ABC_A = 0x02,
  INC_BC = 0x03,
  INC_B = 0x04,
  DEC_B = 0x05,
  LD_B_D8 = 0x06,
  RLCA = 0x07,
  LD_A16_SP = 0x08,
  ADD_HL_BC = 0x09,
  LD_A_ABC = 0x0a,
  DEC_BC = 0x0b,
  INC_C = 0x0c,
  DEC_C = 0x0d,
  LD_C_D8 = 0x0e,
  RRCA = 0x0f,
};

enum prefix : byte {
  // Row 0
};
}  // namespace gbc

#endif
