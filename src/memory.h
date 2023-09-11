#ifndef EMUGB_MEMORY_H
#define EMUGB_MEMORY_H

#include <algorithm>
#include <array>

#include "types.h"

namespace gbc {
class Memory {
 public:
  Memory();

  // Clears memory and fills with all 0s
  void init();

 public:  // Operator overloads
  byte& operator[](word addr);

 private:
  // ROM Bank 00
  // 0x0000 - 0x3fff
  block<0x3fff - 0x0000> ROM_00;

  // ROM Bank 01-NN
  // 0x4000 - 0x7fff
  // TODO

  // VRAM (Bank 00-01)
  // 0x8000 - 0x9fff
  std::array<block<0x9fff - 0x8000>, 2> VRAM;

  // External RAM
  // 0xa000 - 0xbfff
  // TODO

  // WRAM
  // 0xc000 - 0xcfff
  block<0xcfff - 0xc000> WRAM;

  // WRAM Banks 01-07
  // 0xd000 - 0xdfff
  std::array<block<0xdfff - 0xd000>, 7> WRAM_BANK;

  // ECHO RAM
  // 0xe000 - 0xfdff
  // TODO

  // Object Attribute Memory (OAM)
  // 0xfe00 - 0xfe9f
  block<0xfe9f - 0xfe00> OAM;

  // Unsable
  // 0xfea0 - feff
  // Nothing

  // IO Registers
  // 0xff00 - 0xff7f

  // Joypad Input
  /** 0xff00 */ byte P1;

  // Serial Transfer
  /** 0xff01 */ byte SB;
  /** 0xff02 */ byte SC;

  // Timer and Divider
  /** 0xff04 */ byte DIV;
  /** 0xff05 */ byte TIMA;
  /** 0xff06 */ byte TMA;
  /** 0xff07 */ byte TAC;

  // Audio
  // 0xff10 - 0xff26
  // TODO

  // Wave Pattern
  // 0xff30 - 0xff3f
  // TODO

  // LCD
  // 0xff40 - 0xff4b
  /** 0xff40 */ byte LCDC;
  /** 0xff41 */ byte STAT;
  /** 0xff42 */ byte SCY;
  /** 0xff43 */ byte SCX;
  /** 0xff44 */ byte LY;
  /** 0xff45 */ byte LYC;
  /** 0xff47 */ byte BGP;
  /** 0xff48 */ byte OBP0;
  /** 0xff49 */ byte OBP1;
  /** 0xff4a */ byte WY;
  /** 0xff4b */ byte WX;

  // VRAM Bank Select
  /** 0xff4f */ byte VBK;

  // Disable Boot ROM
  /** 0xff50 */ byte BOOT;

  // VRAM DMA
  // 0xff51 - 0xff55
  // TODO

  // Color Palettes
  /** 0xff68 */ byte BCPS;
  /** 0xff69 */ byte BCPD;
  /** 0xff6a */ byte OCPS;
  /** 0xff6b */ byte OCPD;

  // WRAM Bank Select
  /** 0xff70 */ byte SVBK;

  // HRAM
  // 0xff80 - 0xfffe
  block<0xfffe - 0xff80> HRAM;

  // Interrupt Enable
  /** 0xffff */ byte IE;
};
}  // namespace gbc

#endif
