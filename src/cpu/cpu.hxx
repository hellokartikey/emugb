#pragma once

#include "common.hxx"
#include "memory.hxx"
#include "bus.hxx"

namespace gb {
    class CPU {
        Bus& bus;
        Memory& memory;

        byte current;
        cycles_t cycles;

        void nop();
        void stop();
        void ld_r16_d16(word& r16);
        void ld_r8_d8(byte& r8);
        void ld_a16_d8(const word& a16);

    public:
        registers_t regs;

        CPU(Bus& bus, Memory& memory);

        void read_memory(word addr);
        void write_memory(word addr, byte data);

        registers_t get_regs();
        void set_regs(registers_t registers);
        void print_status();

        cycles_t get_cycles();
        byte get_current();

        void reset();
        void init();
        void cycle();
        void fetch();
        void execute(const cycles_t steps=0);
    };
}
