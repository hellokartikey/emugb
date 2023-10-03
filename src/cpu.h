#ifndef EMUGB_CPU_H
#define EMUGB_CPU_H

#include <fmt/core.h>

#include "bus.h"
#include "opcode.h"
#include "types.h"

namespace gbc {
// LR35902 Architecture
class CPU {
 public:
  CPU();
  CPU(Bus& bus);

  // Get cycles
  cycles_t cycles();

  // Registers getters and setters
  registers_t registers();
  void registers(registers_t registers);

  // Initialize to startup state
  void init();

  // Reset all registers to 0
  void reset();

  // Execute instructions for 'steps' cycles (infinite if 'steps' is 0)
  void execute(cycles_t steps = 0);

  // Connect bus
  void connect_bus(Bus& bus);
  bool is_bus_connected();

 private:  // Helpers
  // Interrupt
  void inter();

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
  Bus* bus_ = nullptr;

  registers_t registers_;

  byte fetched_;

  cycles_t cycles_;

 private:  // Opcodes
  // Row 0
  opcode_t nop = [this]() {};
  opcode_t ld_bc_d16 = [this]() { ld_r16_d16(registers_.BC); };
  opcode_t ld_abc_a = [this]() { ld_ar16_r8(registers_.BC, registers_.A); };
  opcode_t inc_bc = [this]() { inc_r16(registers_.BC); };
  opcode_t inc_b = [this]() { inc_r8(registers_.B); };

 private:
  // clang-format off
  table_t opcode_table_ = {
    // Row 0
    {NOP, nop},
    {LD_BC_D16, ld_bc_d16},
    {LD_ABC_A, ld_abc_a},
    {INC_BC, inc_bc},
    {INC_B, inc_b}
  };
  // clang-format on
  table_t prefix_table_;

 private:  // Opcode Generics
  void ld_r16_d16(word& r16);
  void ld_ar16_r8(word& ar16, byte& r8);
  void inc_r16(word& r16);
  void inc_r8(byte& r8);
};
}  // namespace gbc

#endif
