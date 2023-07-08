#pragma once

#include <array>
#include <string>

#include "bus.hxx"
#include "common.hxx"

namespace gb {
class Memory {
  /**
   * 0000 - 0100 : Interrupt Address, RST Adress
   * 0100 - 0150 : ROM Data
   * 0150 - 8000 : User Program Area (32 KB)
   * 8000 - 9800 : Character Data (Bank 0 / 1)
   * 9800 - 9C00 : BG Display Data 1
   * 9C00 - A000 : BG Display Data 2
   * A000 - C000 : External Expansion
   * C000 - D000 : Unit Working RAM (Bank 0, 4KB)
   * D000 - E000 : Unit Working RAM (Bank 1 - 7 Switchable, 4 KB)
   * E000 - FE00 : Echo RAM
   * FE00 - FEA0 : OAM (40 OBJs, 40x32 bits)
   * FEA0 - FF00 : Echo RAM
   * FF00 - FF80 : Input / Output
   * FF80 - FFFE : Working and Stack RAM (127 bytes)
   * FFFE - FFFF : Interrupt Enable
   *
   * Port/Mode Registers
   * FF00        : P1
   * FF01        : SB
   * FF02        : SC
   * FF04        : DIV
   * FF05        : TIMA
   * FF06        : TMA
   * FF07        : TAC
   * FF4D        : KEY1
   * FF56        : RP
   *
   * Bank Control Registers
   * FF0F        : IF
   * FFFF        : IE
   *             : IME
   *
   * LCD Display Registers
   * FF40        : LCDC
   * FF41        : STAT
   * FF42        : SCY
   * FF43        : SCX
   * FF44        : LY
   * FF45        : LYC
   * FF46        : DMA
   * FF47        : BGP
   * FF48        : OBP0
   * FF49        : OBP1
   * FF4A        : WY
   * FF4B        : WX
   * FF4F        : VBK
   * FF51        : HDMA1
   * FF52        : HDMA2
   * FF53        : HDMA3
   * FF54        : HDMA4
   * FF55        : HDMA5
   * FF68        : BCPS
   * FF69        : BCPD
   * FF6A        : OCPS
   * FF6B        : OCPD
   * FE00 - FE9F : OAM
   *
   * Sound Registers
   * FF10 - FF26 : NR x x
   * FF30 - FF3F : Waveform RAM
   */
  // 64 KB memory
  memory_t memory;
  Bus& bus;

 public:
  Memory(Bus& bus);

  /** why constexpr function cannot be defined in cxx file? 😭 */
  constexpr static word size() { return memory_size; }

  void read_bus();
  void load_memory(const memory_t prog);
  memory_t dump_memory();
  memory_t& connect_memory();

  void read_from_file(std::string path);

  void print_memory(word start = 0x0000, int size = 3);

 private:
  byte read(word addr);
  void write(word addr, byte data);
};
}  // namespace gb
