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

// clang-format off
constexpr byte
  // Row 0
  NOP       = 0x00,
  LD_BC_D16 = 0x01,
  LD_ABC_A  = 0x02,
  INC_BC    = 0x03,
  INC_B     = 0x04,
  DEC_B     = 0x05,
  LD_B_D8   = 0x06,
  RLCA      = 0x07,
  LD_A16_SP = 0x08,
  ADD_HL_BC = 0x09,
  LD_A_ABC  = 0x0a,
  DEC_BC    = 0x0b,
  INC_C     = 0x0c,
  DEC_C     = 0x0d,
  LD_C_D8   = 0x0e,
  RRCA      = 0x0f,

  // Row 1
  STOP      = 0x10,
  LD_DE_D16 = 0x11,
  LD_ADE_A  = 0x12,
  INC_DE    = 0x13,
  INC_D     = 0x14,
  DEC_D     = 0x15,
  LD_D_D8   = 0x16,
  RLA       = 0x17,
  JR_R8     = 0x18,
  ADD_HL_DE = 0x19,
  LD_A_ADE  = 0x2a,
  DEC_DE    = 0x2b,
  INC_E     = 0x2c,
  DEC_E     = 0x2d,
  LD_E_D8   = 0x2e,
  RRA       = 0x2f;
// clang-format on
}  // namespace gbc

#endif
