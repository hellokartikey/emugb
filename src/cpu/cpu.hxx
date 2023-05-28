#pragma once

#include "memory.hxx"
#include "common.hxx"

const byte  LD_B_D8     = 0x06,
            LD_C_D8     = 0x0E,
            LD_D_D8     = 0x16,
            LD_E_D8     = 0x1E,
            LD_H_D8     = 0x26,
            LD_L_D8     = 0x2E,

            LD_A_A      = 0x7F,
            LD_A_B      = 0x78,
            LD_A_C      = 0x79,
            LD_A_D      = 0x7A,
            LD_A_E      = 0x7B,
            LD_A_H      = 0x7C,
            LD_A_L      = 0x7D,
            LD_A_HL     = 0X7E,

            NOP         = 0x00,
            HALT        = 0x76;

class CPU {
public:
    // AF = [A [znhcxxxx]]
    union {
        word AF;
        struct {
            struct { byte : 4; byte c: 1; byte h: 1; byte n: 1; byte z: 1; };
            byte A;
        };
    };

    // BC = [B C]
    union {
        word BC;
        struct { byte C; byte B; };
    };

    // DE = [D E]
    union {
        word DE;
        struct { byte E; byte D; };
    };

    // HL = [H L]
    union {
        word HL;
        struct { byte L; byte H; };
    };

    word SP;
    word PC;

    byte IR;
    uint32_t cycles;

    Memory& memory;

public:
    CPU(Memory& mem) : memory(mem) {
        AF = 0;
        BC = 0;
        DE = 0;
        HL = 0;
        SP = 0;
        PC = 0;
        IR = 0;
        cycles = 0;
    };

    // void connect_memory(Memory mem);
    void set_cycles(uint32_t num);
    void fetch();
    void execute();

    void ld(byte& reg);
    void ld(byte& reg, byte data);
    void ld(byte& reg, word addr);
    void halt();
};
