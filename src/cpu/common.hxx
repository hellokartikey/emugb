#pragma once

#include <iostream>
#include <cstdint>
#include <vector>

namespace gb {
    using byte = uint8_t;
    using word = uint16_t;

    using memory = std::array<byte, 0xFFFF>;

    /**
     * R8   :   8 Bit Register
     * R16  :   16 Bit Register
     * D8   :   8 Bit Data
     * D16  :   16 Bit Data
     * A16  :   16 Bit Address
     */
    const byte
    LD_B_D8 = 0x06, LD_C_D8 = 0x0E,
    LD_D_D8 = 0x16, LD_E_D8 = 0x1E,
    LD_H_D8 = 0x26, LD_L_D8 = 0x2E,

    LD_A_A = 0x7F, LD_A_B  = 0x78,
    LD_A_C = 0x79, LD_A_D  = 0x7A,
    LD_A_E = 0x7B, LD_A_H  = 0x7C,
    LD_A_L = 0x7D, LD_A_HL = 0X7E,

    NOP    = 0x00,
    STOP   = 0x10,
    HALT   = 0x76,
    PREFIX = 0xCB,
    DI     = 0xF3,
    EI     = 0xFB,

    JR_R8     = 0x18,
    JR_NZ_R8  = 0x20,
    JR_Z_R8   = 0x28,
    JR_NC_R8  = 0x30,
    JR_C_R8   = 0x38,
    JP_NZ_A16 = 0xC2,
    JP_A16    = 0xC3,
    JP_Z_A16  = 0xCA,
    JP_NC_A16 = 0xD2,
    JP_C_A16  = 0xDA,
    JP_HL     = 0xE9,

    CALL_NZ_A16 = 0xC4,
    CALL_Z_A16  = 0xCC,
    CALL_A16    = 0xCD,
    CALL_NC_A16 = 0xD4,
    CALL_C_A16  = 0xDC,

    RET_NZ = 0xC0,
    RET_Z  = 0xC8,
    RET    = 0xC9,
    RET_NC = 0xD0,
    RET_C  = 0xD8,
    RETI   = 0xD9,

    RST_00 = 0xC7,
    RST_08 = 0xCF,
    RST_10 = 0xD7,
    RST_18 = 0xDF,
    RST_20 = 0xE7,
    RST_28 = 0xEF,
    RST_30 = 0xF7,
    RST_38 = 0xFF
    ;
}
