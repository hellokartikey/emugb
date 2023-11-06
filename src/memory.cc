#include "memory.h"

namespace gbc {
Memory::Memory() {
  reset();
  init();
  bus_ = nullptr;
}

Memory::Memory(Bus& bus) {
  Memory();
  connect_bus(bus);
}

void Memory::init() {}

void Memory::reset() {
  // ROM_00
  ROM_00_.fill(0x00);

  // ROM_01 - NN
  // TODO

  // VRAM
  VRAM_[0].fill(0x00);
  VRAM_[1].fill(0x00);

  // ERAM
  // TODO

  // WRAM
  WRAM_.fill(0x00);

  // WRAM Banks
  WRAM_BANK_[0].fill(0x00);
  WRAM_BANK_[1].fill(0x00);
  WRAM_BANK_[2].fill(0x00);
  WRAM_BANK_[3].fill(0x00);
  WRAM_BANK_[4].fill(0x00);
  WRAM_BANK_[5].fill(0x00);
  WRAM_BANK_[6].fill(0x00);

  // OAM
  OAM_.fill(0x00);

  // Joypad
  P1_ = 0x00;

  // Serial
  SB_ = 0x00;
  SC_ = 0x00;

  // Timer and Divider
  DIV_ = 0x00;
  TIMA_ = 0x00;
  TMA_ = 0x00;
  TAC_ = 0x00;

  // Interrupt
  IF_ = 0x00;

  // Audio
  // TODO

  // Wave Pattern
  // TODO

  // LCD
  LCDC_ = 0x00;
  STAT_ = 0x00;
  SCY_ = 0x00;
  SCX_ = 0x00;
  LY_ = 0x00;
  LYC_ = 0x00;
  DMA_ = 0x00;
  BGP_ = 0x00;
  OBP0_ = 0x00;
  OBP1_ = 0x00;
  WY_ = 0x00;
  WX_ = 0x00;

  // VRAM Bank Select
  VBK_ = 0x00;

  // Disable Boot ROM
  BOOT_ = 0x00;

  // VRAM DMA
  // TODO

  // Color Palettes
  BCPS_ = 0x00;
  BCPD_ = 0x00;
  OCPS_ = 0x00;
  OCPD_ = 0x00;

  // WRAM Bank Select
  SVBK_ = 0x00;

  // HRAM
  HRAM_.fill(0x00);

  // Interrupt Enable
  IE_ = 0x00;

  // Default
  XXX_ = 0x00;
}

void Memory::load_program(const program_t& program, word begin) {
  ROM_00_ = program;
}

void Memory::connect_bus(Bus& bus) {
  bus_ = &bus;
  bus.connect_memory(*this);
}

bool Memory::is_bus_connected() { return bus_ != nullptr; }

byte& Memory::operator[](word addr) {
  auto in = [&](word begin, word end) { return begin <= addr && addr <= end; };
  auto is = [&](enum registers reg) { return addr == reg; };

  XXX_ = 0x00;

  // ROM Bank 00
  if (in(0x0000, 0x3fff)) return ROM_00_[addr];

  // ROM Bank 01-NN
  // TODO

  // VRAM (Bank 00-01)
  if (in(0x8000, 0x9fff)) return VRAM_[VBK_ & 0x01][addr - 0x8000];

  // External RAM
  // TODO

  // WRAM
  if (in(0xc000, 0xcfff)) return WRAM_[addr - 0xc000];

  // WRAM Banks 01-07
  if (in(0xd000, 0xdfff)) {
    byte bank = SVBK_ & 0x07;
    if (bank) {
      bank--;
    }
    return WRAM_BANK_[bank][addr - 0xd000];
  }

  // ECHO RAM
  if (in(0xe000, 0xfdff)) return (*this)[addr - 0x2000];

  // OAM
  if (in(0xfe9f, 0xfe00)) return OAM_[addr - 0xfe9f];

  // HRAM
  if (in(0xff80, 0xfffe)) return HRAM_[addr - 0xff80];

  // IO Registers

  // Joypad Input
  if (is(P1)) return P1_;

  // Serial Transfer
  if (is(SB)) return SB_;
  if (is(SC)) return SC_;

  // Timer and Divider
  if (is(DIV)) return DIV_;
  if (is(TIMA)) return TIMA_;
  if (is(TMA)) return TMA_;
  if (is(TAC)) return TAC_;

  // Interrupt Flag
  if (is(IF)) return IF_;

  // Audio
  // TODO

  // Wave Pattern
  // TODO

  // LCD
  if (is(LCDC)) return LCDC_;
  if (is(STAT)) return STAT_;
  if (is(SCY)) return SCY_;
  if (is(SCX)) return SCX_;
  if (is(LY)) return LY_;
  if (is(LYC)) return LYC_;
  if (is(DMA)) return DMA_;
  if (is(BGP)) return BGP_;
  if (is(OBP0)) return OBP0_;
  if (is(OBP1)) return OBP1_;
  if (is(WY)) return WY_;
  if (is(WX)) return WX_;

  // VRAM Bank Select
  if (VBK) return VBK_;

  // Disable Boot ROM
  if (BOOT) return BOOT_;

  // VRAM DMA
  // TODO

  // Color Palettes
  if (is(BCPS)) return BCPS_;
  if (is(BCPD)) return BCPD_;
  if (is(OCPS)) return OCPS_;
  if (is(OCPD)) return OCPD_;

  // WRAM Bank Select
  if (is(SVBK)) return SVBK_;

  // Interrupt Enable
  if (is(IE)) return IE_;

  return XXX_;
}
}  // namespace gbc