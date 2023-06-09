#pragma once

#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

namespace gb {
using byte = uint8_t;
using word = uint16_t;

using cycles_t = uint32_t;

constexpr byte max_byte = 0xFF;
constexpr word max_word = 0xFFFF;
constexpr word memory_size = 0xFFFF;
constexpr word cartridge_size = 0x8000;

using memory_t = std::array<byte, memory_size>;
using cartridge_t = std::array<byte, 0x8000>;

struct registers_t {
  // AF = [A [znhc xxxx]]
  union {
    word AF;
    struct {
      union {
        byte F;
        struct {
          byte : 4;
          byte c : 1;
          byte h : 1;
          byte n : 1;
          byte z : 1;
        };
      };
      byte A;
    };
  };

  // BC = [B C]
  union {
    word BC;
    struct {
      byte C;
      byte B;
    };
  };

  // DE = [D E]
  union {
    word DE;
    struct {
      byte E;
      byte D;
    };
  };

  // HL = [H L]
  union {
    word HL;
    struct {
      byte L;
      byte H;
    };
  };

  word SP;
  word PC;
};

bool regs_iseq(registers_t regs1, registers_t regs2);
bool carry_add(byte op1, byte op2);
bool half_carry_add(byte op1, byte op2);
bool half_carry_sub(byte op1, byte op2);

byte rand_byte();
word rand_word();

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
constexpr byte
    LD_A_B = 0x78,
    LD_A_C = 0x79, LD_A_D = 0x7A, LD_A_E = 0x7B, LD_A_H = 0x7C, LD_A_L = 0x7D,
    LD_A_A = 0x7F, LD_A_D8 = 0x3E, LD_A_AHL = 0x7E,

    LD_B_B = 0x40, LD_B_C = 0x41, LD_B_D = 0x42, LD_B_E = 0x43, LD_B_H = 0x44,
    LD_B_L = 0x45, LD_B_A = 0x47, LD_B_D8 = 0x06, LD_B_AHL = 0x46,

    LD_C_B = 0x48, LD_C_C = 0x49, LD_C_D = 0x4A, LD_C_E = 0x4B, LD_C_H = 0x4C,
    LD_C_L = 0x4D, LD_C_A = 0x4F, LD_C_D8 = 0x0E, LD_C_AHL = 0x4E,

    LD_D_B = 0x50, LD_D_C = 0x51, LD_D_D = 0x52, LD_D_E = 0x53, LD_D_H = 0x54,
    LD_D_L = 0x55, LD_D_A = 0x57, LD_D_D8 = 0x16, LD_D_AHL = 0x56,

    LD_E_B = 0x58, LD_E_C = 0x59, LD_E_D = 0x5A, LD_E_E = 0x5B, LD_E_H = 0x5C,
    LD_E_L = 0x5D, LD_E_A = 0x5F, LD_E_D8 = 0x1E, LD_E_AHL = 0x5E,

    LD_H_B = 0x60, LD_H_C = 0x61, LD_H_D = 0x62, LD_H_E = 0x63, LD_H_H = 0x64,
    LD_H_L = 0x65, LD_H_A = 0x67, LD_H_D8 = 0x26, LD_H_AHL = 0x66,

    LD_L_B = 0x68, LD_L_C = 0x69, LD_L_D = 0x6A, LD_L_E = 0x6B, LD_L_H = 0x6C,
    LD_L_L = 0x6D, LD_L_A = 0x6F, LD_L_D8 = 0x2E, LD_L_AHL = 0x6E,

    LD_AHL_B = 0x70, LD_AHL_C = 0x71, LD_AHL_D = 0x72, LD_AHL_E = 0x73,
    LD_AHL_H = 0x74, LD_AHL_L = 0x75, LD_AHL_A = 0x77, LD_AHL_D8 = 0x36,
    LD_AHLP_A = 0x22, LD_A_AHLP = 0x2A, LD_AHLM_A = 0x32, LD_A_AHLM = 0x3A,

    LD_ABC_A = 0x02, LD_A_ABC = 0x0A, LD_ADE_A = 0x12, LD_A_ADE = 0x1A,

    LD_BC_D16 = 0x01, LD_DE_D16 = 0x11, LD_HL_D16 = 0x21, LD_A16_SP = 0x08,
    LD_SP_D16 = 0x31, LD_SP_HL = 0xF9, LD_HL_SP_R8 = 0xF8,

    LDH_A8_A = 0xE0, LDH_A_A8 = 0xF0, LD_AC_A = 0xE2, LD_A_AC = 0xF2,
    LD_A16_A = 0xEA, LD_A_A16 = 0xFA,

    RLCA = 0x07, RRCA = 0x0F, RLA = 0x17, RRA = 0x1F,

    ADD_A_B = 0x80, ADD_A_C = 0x81, ADD_A_D = 0x82, ADD_A_E = 0x83,
    ADD_A_H = 0x84, ADD_A_L = 0x85, ADD_A_A = 0x87, ADD_A_D8 = 0xC6,
    ADD_A_AHL = 0x86,

    SUB_B = 0x90, SUB_C = 0x91, SUB_D = 0x92, SUB_E = 0x93, SUB_H = 0x94,
    SUB_L = 0x95, SUB_A = 0x97, SUB_D8 = 0xD6, SUB_AHL = 0x96,

    AND_B = 0xA0, AND_C = 0xA1, AND_D = 0xA2, AND_E = 0xA3, AND_H = 0xA4,
    AND_L = 0xA5, AND_A = 0xA7, AND_D8 = 0xE6, AND_AHL = 0xA6,

    OR_B = 0xB0, OR_C = 0xB1, OR_D = 0xB2, OR_E = 0xB3, OR_H = 0xB4,
    OR_L = 0xB5, OR_A = 0xB7, OR_D8 = 0xF6, OR_AHL = 0xB6,

    ADC_A_B = 0x88, ADC_A_C = 0x89, ADC_A_D = 0x8A, ADC_A_E = 0x8B,
    ADC_A_H = 0x8C, ADC_A_L = 0x8D, ADC_A_A = 0x8F, ADC_A_D8 = 0xCE,
    ADC_A_AHL = 0x8E,

    SBC_A_B = 0x98, SBC_A_C = 0x99, SBC_A_D = 0x9A, SBC_A_E = 0x9B,
    SBC_A_H = 0x9C, SBC_A_L = 0x9D, SBC_A_A = 0x9F, SBC_A_D8 = 0xDE,
    SBC_A_AHL = 0x9E,

    XOR_B = 0xA8, XOR_C = 0xA9, XOR_D = 0xAA, XOR_E = 0xAB, XOR_H = 0xAC,
    XOR_L = 0xAD, XOR_A = 0xAF, XOR_D8 = 0xEE, XOR_AHL = 0xAE,

    CP_B = 0xB8, CP_C = 0xB9, CP_D = 0xBA, CP_E = 0xBB, CP_H = 0xBC,
    CP_L = 0xBD, CP_A = 0xBF, CP_D8 = 0xFE, CP_AHL = 0xBE,

    POP_AF = 0xF1, POP_BC = 0xC1, POP_DE = 0xD1, POP_HL = 0xE1, PUSH_AF = 0xF5,
    PUSH_BC = 0xC5, PUSH_DE = 0xD5, PUSH_HL = 0xE5,

    NOP = 0x00, STOP = 0x10, HALT = 0x76, PREFIX = 0xCB, DI = 0xF3, EI = 0xFB,

    JR_NZ_R8 = 0x20, JR_Z_R8 = 0x28, JR_NC_R8 = 0x30, JR_C_R8 = 0x38,
    JP_NZ_A16 = 0xC2, JP_Z_A16 = 0xCA, JR_R8 = 0x18, JP_A16 = 0xC3,
    JP_NC_A16 = 0xD2, JP_C_A16 = 0xDA, JP_HL = 0xE9,

    CALL_NZ_A16 = 0xC4, CALL_Z_A16 = 0xCC, CALL_NC_A16 = 0xD4,
    CALL_C_A16 = 0xDC, CALL_A16 = 0xCD,

    RET_NZ = 0xC0, RET_Z = 0xC8, RET_NC = 0xD0, RET_C = 0xD8, RET = 0xC9,
    RETI = 0xD9,

    RST_00 = 0xC7, RST_08 = 0xCF, RST_10 = 0xD7, RST_18 = 0xDF, RST_20 = 0xE7,
    RST_28 = 0xEF, RST_30 = 0xF7, RST_38 = 0xFF,

    INC_B = 0x04, INC_D = 0x14, INC_H = 0x24, INC_AHL = 0x34, INC_C = 0x0C,
    INC_E = 0x1C, INC_L = 0x2C, INC_A = 0x3C, DEC_B = 0x05, DEC_D = 0x15,
    DEC_H = 0x25, DEC_AHL = 0x35, DEC_C = 0x0D, DEC_E = 0x1D, DEC_L = 0x2D,
    DEC_A = 0x3D,

    DAA = 0x27, SCF = 0x37, CPL = 0x2F, CCF = 0x3F,

    INC_BC = 0x03, INC_DE = 0x13, INC_HL = 0x23, INC_SP = 0x33, DEC_BC = 0x0B,
    DEC_DE = 0x1B, DEC_HL = 0x2B, DEC_SP = 0x3B, ADD_HL_BC = 0x09,
    ADD_HL_DE = 0x19, ADD_HL_HL = 0x29, ADD_HL_SP = 0x39, ADD_SP_R8 = 0xE8;
}  // namespace gb
