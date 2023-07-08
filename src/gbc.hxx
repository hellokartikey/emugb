#pragma once

#include "bus.hxx"
#include "common.hxx"
#include "cpu.hxx"
#include "disassembler.hxx"
#include "joypad.hxx"
#include "memory.hxx"
#include "screen.hxx"
#include "speaker.hxx"

namespace gb {
class GameBoy {
  Bus bus;
  Memory memory;
  CPU cpu;
  Joypad joypad;
  Screen screen;
  Speaker speaker;
  Disassembler disassembler;

 public:
  GameBoy();
  void run();
  void read_rom(const std::string path);
};
}  // namespace gb
