#pragma once

#include <iostream>
#include <cstdint>
#include <vector>

namespace gb {
    using byte = uint8_t;
    using word = uint16_t;

    constexpr byte max_byte = 0xFF;
    constexpr word max_word = 0xFFFF;
    constexpr word memory_size = 0xFFFF;
    constexpr word cartridge_size = 0x8000;

    using memory = std::array<byte, memory_size>;
    using cartridge = std::array<byte, 0x8000>;

    /**
     * R8   :   8 Bit Register
     * R16  :   16 Bit Register
     * D8   :   8 Bit Data
     * D16  :   16 Bit Data
     * A16  :   16 Bit Address
     * 
     * NZ   :   Not Zero
     * Z    :   Zero
     * NC   :   No Carry
     * C    :   Carry
     */
    constexpr byte
    LD_B_D8 = 0x06, LD_C_D8 = 0x0E, LD_D_D8 = 0x16,
    LD_E_D8 = 0x1E, LD_H_D8 = 0x26, LD_L_D8 = 0x2E,

    LD_A_A = 0x7F, LD_A_B  = 0x78, LD_A_C = 0x79, LD_A_D  = 0x7A,
    LD_A_E = 0x7B, LD_A_H  = 0x7C, LD_A_L = 0x7D, LD_A_HL = 0X7E,

    LD_BC_D16   = 0x01, LD_DE_D16 = 0x11, LD_HL_D16 = 0x21,
    LD_A16_SP   = 0x08, LD_SP_D16 = 0x31, LD_SP_HL  = 0xF9,
    LD_HL_SP_R8 = 0xF8,

    POP_AF  = 0xF1, POP_BC  = 0xC1, POP_DE  = 0xD1, POP_HL  = 0xE1,
    PUSH_AF = 0xF5, PUSH_BC = 0xC5, PUSH_DE = 0xD5, PUSH_HL = 0xE5,

    NOP = 0x00, STOP = 0x10, HALT = 0x76, PREFIX = 0xCB, DI = 0xF3, EI = 0xFB,

    JR_NZ_R8  = 0x20, JR_Z_R8  = 0x28, JR_NC_R8  = 0x30, JR_C_R8  = 0x38,
    JP_NZ_A16 = 0xC2, JP_Z_A16 = 0xCA, JR_R8     = 0x18, JP_A16   = 0xC3,
    JP_NC_A16 = 0xD2, JP_C_A16 = 0xDA, JP_HL     = 0xE9,

    CALL_NZ_A16 = 0xC4, CALL_Z_A16 = 0xCC, CALL_NC_A16 = 0xD4,
    CALL_C_A16  = 0xDC, CALL_A16   = 0xCD,

    RET_NZ = 0xC0, RET_Z = 0xC8, RET_NC = 0xD0,
    RET_C  = 0xD8, RET   = 0xC9, RETI   = 0xD9,

    RST_00 = 0xC7, RST_08 = 0xCF, RST_10 = 0xD7, RST_18 = 0xDF,
    RST_20 = 0xE7, RST_28 = 0xEF, RST_30 = 0xF7, RST_38 = 0xFF,

    INC_B = 0x04, INC_D = 0x14, INC_H = 0x24, INC_AHL = 0x34,
    INC_C = 0x0C, INC_E = 0x1C, INC_L = 0x2C, INC_A   = 0x3C,
    DEC_B = 0x05, DEC_D = 0x15, DEC_H = 0x25, DEC_AHL = 0x35,
    DEC_C = 0x0D, DEC_E = 0x1D, DEC_L = 0x2D, DEC_A   = 0x3D,

    DAA = 0x27, SCF = 0x37, CPL = 0x2F, CCF = 0x3F,

    INC_BC    = 0x03, INC_DE    = 0x13, INC_HL    = 0x23, INC_SP    = 0x33,
    DEC_BC    = 0x0B, DEC_DE    = 0x1B, DEC_HL    = 0x2B, DEC_SP    = 0x3B,
    ADD_HL_BC = 0x09, ADD_HL_DE = 0x19, ADD_HL_HL = 0x29, ADD_HL_SP = 0x39,
    ADD_SP_R8 = 0xE8
    ;

    byte rand_byte();
    word rand_word();
}
