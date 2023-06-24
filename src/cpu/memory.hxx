#pragma once

#include <array>

#include "common.hxx"
#include "bus.hxx"

namespace gb {
    class Memory {
        /**
         * 0000 - 3fff : Cartrigde
         * 4000 - 7fff : Memory bank controller from cartrige
         * 8000 - 9fff : Video RAM
         * a000 - bfff : External RAM
         * c000 - dfff : Work RAM
         * e000 - fdff : Mirror of c000 - ddff (prohibited)
         * fe00 - fe9f : Sprite attribute table
         * fea0 - feff : Not usable
         * ff00 - ff7f : IO registers
         * ff80 - fffe : High RAM
         * ffff - ffff : Interrupt Enable register
         *
         * IO Ranges
         * ff00        : Joypad input
         * ff01 - ff02 : Serial transfer
         * ff04 - ff07 : Timer and divider
         * ff10 - ff26 : Audio
         * ff30 - ff3f : Wave pattern
         * ff40 - ff4b : LCD
         * ff4f        : VRAM bank select
         * ff50        : Enable/disable boot ROM
         * ff51 - ff55 : VRAM DMA
         * ff68 - ff69 : BG/OBJ Palettes
         * ff70        : WRAM bank select
         */

        // 64 KB memory
        memory_t memory;
        Bus& bus;

    public:
        Memory(Bus& bus);

        void read_bus();
        void load_memory(const memory_t prog);
        memory_t dump_memory();

        /** why constexpr function cannot be defined in cxx file? 😭 */
        constexpr static word size() { return memory_size; }

    private:
        byte read(word addr);
        void write(word addr, byte data);
    };
}
