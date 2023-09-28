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
enum opcode : byte { NOP = 0x00 };
}  // namespace gbc

#endif
