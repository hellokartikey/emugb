#include <fmt/core.h>

#include <iostream>

#include "bus.hxx"
#include "cpu.hxx"
#include "disassembler.hxx"
#include "gbc.hxx"
#include "joypad.hxx"
#include "memory.hxx"
#include "screen.hxx"
#include "speaker.hxx"

int main() {
  gb::GameBoy gbc;
  // gbc.read_rom("/home/arch/Desktop/gbc_bios.bin");
  // gbc.run();

  gbc.shell();

  return 0;
}
