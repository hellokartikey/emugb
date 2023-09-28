#include "memory.h"

namespace gbc {
Memory::Memory() { init(); }

void Memory::init() {}

void Memory::reset() {
  // ROM_00
  ROM_00.fill(0x00);

  // ROM_01 - NN
  // TODO

  // VRAM
  VRAM[0].fill(0x00);
  VRAM[1].fill(0x00);

  // ERAM
  // TODO

  // WRAM
  WRAM.fill(0x00);

  // WRAM Banks
  WRAM_BANK[0].fill(0x00);
  WRAM_BANK[1].fill(0x00);
  WRAM_BANK[2].fill(0x00);
  WRAM_BANK[3].fill(0x00);
  WRAM_BANK[4].fill(0x00);
  WRAM_BANK[5].fill(0x00);
  WRAM_BANK[6].fill(0x00);

  // OAM
  OAM.fill(0x00);

  // Joypad
  P1 = 0x00;

  // Serial
  SB = 0x00;
  SC = 0x00;

  // Timer and Divider
  DIV = 0x00;
  TIMA = 0x00;
  TMA = 0x00;
  TAC = 0x00;

  // Interrupt
  IF = 0x00;

  // Audio
  // TODO

  // Wave Pattern
  // TODO

  // LCD
  LCDC = 0x00;
  STAT = 0x00;
  SCY = 0x00;
  SCX = 0x00;
  LY = 0x00;
  LYC = 0x00;
  DMA = 0x00;
  BGP = 0x00;
  OBP0 = 0x00;
  OBP1 = 0x00;
  WY = 0x00;
  WX = 0x00;

  // VRAM Bank Select
  VBK = 0x00;

  // Disable Boot ROM
  BOOT = 0x00;

  // VRAM DMA
  // TODO

  // Color Palettes
  BCPS = 0x00;
  BCPD = 0x00;
  OCPS = 0x00;
  OCPD = 0x00;

  // WRAM Bank Select
  SVBK = 0x00;

  // HRAM
  std::fill(HRAM.begin(), HRAM.end(), 0x00);

  // Interrupt Enable
  IE = 0x00;

  // Default
  XXX = 0x00;
}

byte& Memory::operator[](word addr) {
  XXX = 0x00;

  // ROM Bank 00
  if (in(addr, 0x0000, 0x3fff)) return ROM_00[addr];

  // ROM Bank 01-NN
  // TODO

  // VRAM (Bank 00-01)
  if (in(addr, 0x8000, 0x9fff)) return VRAM[VBK & 0x01][addr - 0x8000];

  // External RAM
  // TODO

  // WRAM
  if (in(addr, 0xc000, 0xcfff)) return WRAM[addr - 0xc000];

  // WRAM Banks 01-07
  if (in(addr, 0xd000, 0xdfff)) {
    byte bank = SVBK & 0x07;
    if (bank) {
      bank--;
    }
    return WRAM_BANK[bank][addr - 0xd000];
  }

  // ECHO RAM
  if (in(addr, 0xe000, 0xfdff)) return (*this)[addr - 0x2000];

  // OAM
  if (in(addr, 0xfe9f, 0xfe00)) return OAM[addr - 0xfe9f];

  // HRAM
  if (in(addr, 0xff80, 0xfffe)) return HRAM[addr - 0xff80];

  // IO Registers

  // Joypad Input
  if (addr == 0xff00) return P1;

  // Serial Transfer
  if (addr == 0xff01) return SB;
  if (addr == 0xff02) return SC;

  // Timer and Divider
  if (addr == 0xff04) return DIV;
  if (addr == 0xff05) return TIMA;
  if (addr == 0xff06) return TMA;
  if (addr == 0xff07) return TAC;

  // Interrupt Flag
  if (addr == 0xff0f) return IF;

  // Audio
  // TODO

  // Wave Pattern
  // TODO

  // LCD
  if (addr == 0xff40) return LCDC;
  if (addr == 0xff41) return STAT;
  if (addr == 0xff42) return SCY;
  if (addr == 0xff43) return SCX;
  if (addr == 0xff44) return LY;
  if (addr == 0xff45) return LYC;
  if (addr == 0xff46) return DMA;
  if (addr == 0xff47) return BGP;
  if (addr == 0xff48) return OBP0;
  if (addr == 0xff49) return OBP1;
  if (addr == 0xff4a) return WY;
  if (addr == 0xff4b) return WX;

  // VRAM Bank Select
  if (addr == 0xff4f) return VBK;

  // Disable Boot ROM
  if (addr == 0xff50) return BOOT;

  // VRAM DMA
  // TODO

  // Color Palettes
  if (addr == 0xff68) return BCPS;
  if (addr == 0xff69) return BCPD;
  if (addr == 0xff6a) return OCPS;
  if (addr == 0xff6b) return OCPD;

  // WRAM Bank Select
  if (addr == 0xff70) return SVBK;

  // Interrupt Enable
  if (addr == 0xffff) return IE;

  return XXX;
}

void Memory::load_program(const program_t& program, word begin) {
  ROM_00 = program;
}

bool Memory::in(word addr, word begin, word end) {
  return begin <= addr && addr <= end;
}
}  // namespace gbc