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

  std::string shell_prompt = "$ ";

 public:
  GameBoy();
  void run();
  void read_rom(const std::string path);
  /**
   * The Game Boy Color shell commands
   * [0] exit
   * [1] run
   * [2] rom <path>
   * [3] dump <addr> <lines: optional>
   * [4] regs
   * [5] dasm <addr>
   */
  void shell();
};
}  // namespace gb
