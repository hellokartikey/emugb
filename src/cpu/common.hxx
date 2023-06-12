#pragma once

#include <iostream>
#include <cstdint>
#include <vector>

namespace gb {
    using byte = uint8_t;
    using word = uint16_t;

    using program = std::vector<byte>;

    /**
     * R8   : 8 Bit Register
     * R16  : 16 Bit Register
     * D8   : 8 Bit Data
     * D16  : 16 Bit Data
     */
    const byte
    LD_B_D8 = 0x06, LD_C_D8 = 0x0E,
    LD_D_D8 = 0x16, LD_E_D8 = 0x1E,
    LD_H_D8 = 0x26, LD_L_D8 = 0x2E,

    LD_A_A = 0x7F, LD_A_B  = 0x78,
    LD_A_C = 0x79, LD_A_D  = 0x7A,
    LD_A_E = 0x7B, LD_A_H  = 0x7C,
    LD_A_L = 0x7D, LD_A_HL = 0X7E,

    NOP  = 0x00,
    HALT = 0x76;
}
