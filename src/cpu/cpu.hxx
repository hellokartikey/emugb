#pragma once

#include "common.hxx"
#include "memory.hxx"
#include "bus.hxx"

namespace gb {
    class CPU {
        byte current;
        cycles_t cycles;

        Bus& bus;
        Memory& memory;

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
        void execute();
    };
}
