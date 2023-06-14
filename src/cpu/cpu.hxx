#pragma once

#include "common.hxx"
#include "memory.hxx"
#include "bus.hxx"

namespace gb {
    class CPU {
    public:
        // AF = [A [znhcxxxx]]
        union {
            word AF;
            struct {
                union {
                    byte F;
                    struct {
                        byte  : 4;
                        byte c: 1;
                        byte h: 1;
                        byte n: 1;
                        byte z: 1;
                    };
                };
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

        Bus& bus;
        Memory& memory;

    public:
        CPU(Bus& bus, Memory& memory);

        void read_memory(word addr);
        void write_memory(word addr, byte data);

        void reset();
        void init();
        void fetch();
        void execute();

        void ld(byte& reg);
        void ld(byte& reg, byte data);
        void ld(byte& reg, word addr);
        void inc(byte& reg);
        void halt();
    };
}
