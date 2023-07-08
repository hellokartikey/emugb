#pragma once

#include "common.hxx"
#include "memory.hxx"

namespace gb {
class Disassembler {
  const memory_t& memory;

 public:
  Disassembler(const memory_t& memory);
  void disassemble(word start = 0x0000, int instructions = 5);
  std::string get_instruction(word& addr);
};
}  // namespace gb