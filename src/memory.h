#ifndef EMUGB_MEMORY_H
#define EMUGB_MEMORY_H

#include <algorithm>
#include <array>

#include "bus.h"
#include "types.h"

namespace gbc {
class Memory {
 public:
  Memory();
  Memory(Bus& bus);

  // Initializes memory with default bytes
  void init();

  // Resets all bytes to 0
  void reset();

  // Load inline programs into the ROM bank 00
  void load_program(const program_t& program, word begin = 0x0000);

  // Connect bus
  void connect_bus(Bus& bus);
  bool is_bus_connected();

 public:  // Operator overloads
  byte& operator[](word addr);

 public:  // Register enum
  enum registers : word {
    // Joypad Input
    P1 = 0xff00,
    // Serial Transfer
    SB = 0xff01,
    SC = 0xff02,
    // Timer and Divider
    DIV = 0xff04,
    TIMA = 0xff05,
    TMA = 0xff06,
    TAC = 0xff07,
    // Interrupt Flag
    IF = 0xff0f,

    // Audio Pattern
    // TODO

    // Wave Pattern
    // TODO

    // LCD
    LCDC = 0xff40,
    STAT = 0xff41,
    SCY = 0xff42,
    SCX = 0xff43,
    LY = 0xff44,
    LYC = 0xff45,
    DMA = 0xff46,
    BGP = 0xff47,
    OBP0 = 0xff48,
    OBP1 = 0xff49,
    WY = 0xff4a,
    WX = 0xff4b,

    // VRAM Bank Select
    VBK = 0xff4f,

    // Disable Boot ROM
    BOOT = 0xff50,

    // VRAM DMA
    // TODO

    // Color Palettes
    BCPS = 0xff68,
    BCPD = 0xff69,
    OCPS = 0xff6a,
    OCPD = 0xff6b,

    // WRAM Bank Select
    SVBK = 0xff70,

    // Interrupt Enable
    IE = 0xffff
  };

 private:  // Members
  Bus* bus_;

 private:  // Blocks
  // ROM Bank 00
  // 0x0000 - 0x3fff
  block_t<0x3fff - 0x0000> ROM_00_;

  // ROM Bank 01-NN
  // 0x4000 - 0x7fff
  // TODO

  // VRAM (Bank 00-01)
  // 0x8000 - 0x9fff
  std::array<block_t<0x9fff - 0x8000>, 2> VRAM_;

  // External RAM
  // 0xa000 - 0xbfff
  // TODO

  // WRAM
  // 0xc000 - 0xcfff
  block_t<0xcfff - 0xc000> WRAM_;

  // WRAM Banks 01-07
  // 0xd000 - 0xdfff
  std::array<block_t<0xdfff - 0xd000>, 7> WRAM_BANK_;

  // ECHO RAM
  // 0xe000 - 0xfdff
  // Implemented in operator[]

  // Object Attribute Memory (OAM)
  // 0xfe00 - 0xfe9f
  block_t<0xfe9f - 0xfe00> OAM_;

  // Unsable
  // 0xfea0 - feff
  // Nothing

  // IO Registers
  // 0xff00 - 0xff7f

  // Joypad Input
  /** 0xff00 */ byte P1_;

  // Serial Transfer
  /** 0xff01 */ byte SB_;
  /** 0xff02 */ byte SC_;

  // Timer and Divider
  /** 0xff04 */ byte DIV_;
  /** 0xff05 */ byte TIMA_;
  /** 0xff06 */ byte TMA_;
  /** 0xff07 */ byte TAC_;

  // Interrupt Flag
  /** 0xff0f */ byte IF_;

  // Audio
  // 0xff10 - 0xff26
  // TODO

  // Wave Pattern
  // 0xff30 - 0xff3f
  // TODO

  // LCD
  // 0xff40 - 0xff4b
  /** 0xff40 */ byte LCDC_;
  /** 0xff41 */ byte STAT_;
  /** 0xff42 */ byte SCY_;
  /** 0xff43 */ byte SCX_;
  /** 0xff44 */ byte LY_;
  /** 0xff45 */ byte LYC_;
  /** 0xff46 */ byte DMA_;
  /** 0xff47 */ byte BGP_;
  /** 0xff48 */ byte OBP0_;
  /** 0xff49 */ byte OBP1_;
  /** 0xff4a */ byte WY_;
  /** 0xff4b */ byte WX_;

  // VRAM Bank Select
  /** 0xff4f */ byte VBK_;

  // Disable Boot ROM
  /** 0xff50 */ byte BOOT_;

  // VRAM DMA
  // 0xff51 - 0xff55
  // TODO

  // Color Palettes
  /** 0xff68 */ byte BCPS_;
  /** 0xff69 */ byte BCPD_;
  /** 0xff6a */ byte OCPS_;
  /** 0xff6b */ byte OCPD_;

  // WRAM Bank Select
  /** 0xff70 */ byte SVBK_;

  // HRAM
  // 0xff80 - 0xfffe
  block_t<0xfffe - 0xff80> HRAM_;

  // Interrupt Enable
  /** 0xffff */ byte IE_;

  // XXX Address returned when invalid address
  /** 0xxxxx */ byte XXX_ = 0x00;
};
}  // namespace gbc

#endif
