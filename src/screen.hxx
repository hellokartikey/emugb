#pragma once

#include <array>

#include "common.hxx"

namespace gb {
    class Screen {
        byte width = 160;
        byte height = 144;

        const std::array<byte&, 0x400> BG_Data1, BG_Data2;
        const std::array<byte&, 0x1800> character_data;
        const byte&
        VBK, LCDC, STAT, SCY, SCX, LY, LYC, BGP, OBP0, OBP1, WY, WX;
    };
}