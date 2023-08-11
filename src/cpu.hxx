#pragma once

#include "bus.hxx"
#include "common.hxx"
#include "memory.hxx"

namespace gb {
class CPU {
  registers_t regs;

  Bus& bus;
  Memory& memory;

  byte current;
  cycles_t cycles;

  void unrecognized();
  void nop();
  void stop();
  void ld_r16_d16(word& r16);
  void ld_r16_r16(word& r16_dst, word r16_src);
  void ld_r16_r16_r8(word& r16_dst, word r16_src);
  void ld_r8_d8(byte& r8);
  void ld_a16_d8(word& a16);
  void ld_r8_r8(byte& r8_dst, byte r8_src);
  void ld_r8_ar16(byte& r8, word a16);
  void ld_a16_r8(word a16, byte r8);
  void ld_a16_r16(word& r16);
  void ld_a8_r8(byte r8);
  void ld_r8_a8(byte& r8);
  void ld_ar8_r8(byte ar8, byte r8);
  void ld_r8_ar8(byte& r8, byte ar8);
  void ld_r8_a16(byte& r8);
  void ld_a16_r8(byte r8);
  void push(word r16);
  void pop(word& r16);
  void inc(byte& r8);
  void inc(word& r16);
  void inc();
  void dec(byte& r8);
  void dec(word& r16);
  void dec();
  void rst(word addr);
  void rlca();
  void rrca();
  void rla();
  void rra();
  void jp();
  void jp_ar16(word ar16);
  void jp_nz();
  void jp_nc();
  void jp_z();
  void jp_c();

 public:
  CPU(Bus& bus, Memory& memory);

  void read_memory(word addr);
  void write_memory(word addr, byte data);

  registers_t get_regs();
  void set_regs(registers_t registers);
  void print_status();

  cycles_t get_cycles();
  byte get_current();

  void reset();
  void init();
  void cycle();
  void fetch();
  void execute(const cycles_t steps = 0);
};
}  // namespace gb
