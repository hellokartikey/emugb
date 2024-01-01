#ifndef EMUGB_CPU_H
#define EMUGB_CPU_H

#include <hk/signal.h>

#include "common.h"
#include "registers.h"

namespace gbc {
class CPU {
 public:
  CPU();
  ~CPU();

 public:
  // Reset the CPU
  auto reset() -> void;

  // Handle interrupts
  auto iter() -> void;

  // Execute an instruction
  auto exec() -> void;

  // Execute num instructions
  auto exec_n(cycles n = 0) -> void;

  // Get clocks
  auto clock() -> cycles;

 private:
  // Read/write bytes from/to memory
  auto read(word addr) -> byte;
  auto write(word addr, byte data) -> void;

  // Read/write words from/to memory
  auto read16(word addr) -> word;
  auto write16(word addr, word data) -> void;

  // Cycle
  auto cycle() -> void;

  // Fetch next instruction from memory
  auto fetch() -> byte;

 public:  // Signals and Slots
  hk::signals::Signal<word> write_addr_to_bus;
  hk::signals::Signal<byte> write_data_to_bus;
  auto read_data_from_bus(byte data) -> void;

 private:  // Members
  R16 AF, BC, DE, HL, SP, PC;
  byte& A;
  byte& B;
  byte& C;
  byte& D;
  byte& E;
  byte& H;
  byte& L;

  byte data_bus;
  word addr_bus;

  cycles clocks;
};
}  // namespace gbc

#endif
