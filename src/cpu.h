#ifndef EMUGB_CPU_H
#define EMUGB_CPU_H

#include <fmt/core.h>

#include "opcode.h"
#include "types.h"

namespace gbc {
class Bus;

// LR35902 Architecture
class CPU {
 public:
  CPU();
  CPU(Bus& bus);
  CPU(Bus* bus);

  // Initialize to startup state
  void init();

  // Execute instructions for 'steps' cycles (infinite if 'steps' is 0)
  void execute(cycles_t steps = 0);

  // Reset all registers to 0
  void reset();

  // Interrupt
  void inter();

  // Connect bus
  void connect_bus(Bus& bus);
  void connect_bus(Bus* bus);
  bool is_bus_connected();

 private:  // Helpers
  // Read from memory
  byte read(word addr);
  word read16(word addr);

  // Write to memory
  void write(word addr, byte data);
  void write16(word addr, word data);

  // Stack Operations
  void push(word data);
  word pop();

  // Fetch next instruction (increments PC) and stores into 'fetch'
  void fetch();

  // Generate a machine cycle (4 clock cycles)
  void cycle();

 private:  // Members
  Bus* bus;

  registers_t registers;

  byte fetched;

  cycles_t cycles;

  table_t opcode_table;
  table_t prefix_table;

 private:  // Opcodes
};
}  // namespace gbc

#endif
