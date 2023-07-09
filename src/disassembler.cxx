#include "disassembler.hxx"

#include <fmt/core.h>

namespace gb {
Disassembler::Disassembler(const memory_t& memory) : memory(memory) {}

void Disassembler::disassemble(word addr, int instructions) {
  for (int i = 0; i < instructions; i++) {
    fmt::print("{}\n", get_instruction(addr));
  }
}

std::string Disassembler::get_instruction(word& addr) {
  std::string addr_spacer = " - ";
  std::string tab = "\t- ";
  std::string instruction = fmt::format("{:04x}", addr);
  byte opcode = memory[addr++];
  instruction += addr_spacer + fmt::format("{:02x} ", opcode);
  switch (opcode) {
    case NOP:
      instruction += tab + fmt::format("NOP");
      break;
      break;
    case LD_B_B:
      instruction += tab + fmt::format("LD B, B");
      break;
    case LD_B_C:
      instruction += tab + fmt::format("LD B, C");
      break;
    case LD_B_D:
      instruction += tab + fmt::format("LD B, D");
      break;
    case LD_B_E:
      instruction += tab + fmt::format("LD B, E");
      break;
    case LD_B_H:
      instruction += tab + fmt::format("LD B, H");
      break;
    case LD_B_L:
      instruction += tab + fmt::format("LD B, L");
      break;
    case LD_B_AHL:
      instruction += tab + fmt::format("LD B, (HL)");
      break;
    case LD_B_A:
      instruction += tab + fmt::format("LD B, A");
      break;

    case LD_C_B:
      instruction += tab + fmt::format("LD C, B");
      break;
    case LD_C_C:
      instruction += tab + fmt::format("LD C, C");
      break;
    case LD_C_D:
      instruction += tab + fmt::format("LD C, D");
      break;
    case LD_C_E:
      instruction += tab + fmt::format("LD C, E");
      break;
    case LD_C_H:
      instruction += tab + fmt::format("LD C, H");
      break;
    case LD_C_L:
      instruction += tab + fmt::format("LD C, L");
      break;
    case LD_C_AHL:
      instruction += tab + fmt::format("LD C, (HL)");
      break;
    case LD_C_A:
      instruction += tab + fmt::format("LD C, A");
      break;

    case LD_D_B:
      instruction += tab + fmt::format("LD D, B");
      break;
    case LD_D_C:
      instruction += tab + fmt::format("LD D, C");
      break;
    case LD_D_D:
      instruction += tab + fmt::format("LD D, D");
      break;
    case LD_D_E:
      instruction += tab + fmt::format("LD D, E");
      break;
    case LD_D_H:
      instruction += tab + fmt::format("LD D, H");
      break;
    case LD_D_L:
      instruction += tab + fmt::format("LD D, L");
      break;
    case LD_D_AHL:
      instruction += tab + fmt::format("LD D, (HL)");
      break;
    case LD_D_A:
      instruction += tab + fmt::format("LD D, A");
      break;

    case LD_E_B:
      instruction += tab + fmt::format("LD E, B");
      break;
    case LD_E_C:
      instruction += tab + fmt::format("LD E, C");
      break;
    case LD_E_D:
      instruction += tab + fmt::format("LD E, D");
      break;
    case LD_E_E:
      instruction += tab + fmt::format("LD E, E");
      break;
    case LD_E_H:
      instruction += tab + fmt::format("LD E, H");
      break;
    case LD_E_L:
      instruction += tab + fmt::format("LD E, L");
      break;
    case LD_E_AHL:
      instruction += tab + fmt::format("LD E, (HL)");
      break;
    case LD_E_A:
      instruction += tab + fmt::format("LD E, A");
      break;

    case LD_H_B:
      instruction += tab + fmt::format("LD H, B");
      break;
    case LD_H_C:
      instruction += tab + fmt::format("LD H, C");
      break;
    case LD_H_D:
      instruction += tab + fmt::format("LD H, D");
      break;
    case LD_H_E:
      instruction += tab + fmt::format("LD H, E");
      break;
    case LD_H_H:
      instruction += tab + fmt::format("LD H, H");
      break;
    case LD_H_L:
      instruction += tab + fmt::format("LD H, L");
      break;
    case LD_H_AHL:
      instruction += tab + fmt::format("LD H, (HL)");
      break;
    case LD_H_A:
      instruction += tab + fmt::format("LD H, A");
      break;

    case LD_L_B:
      instruction += tab + fmt::format("LD L, B");
      break;
    case LD_L_C:
      instruction += tab + fmt::format("LD L, C");
      break;
    case LD_L_D:
      instruction += tab + fmt::format("LD L, D");
      break;
    case LD_L_E:
      instruction += tab + fmt::format("LD L, E");
      break;
    case LD_L_H:
      instruction += tab + fmt::format("LD L, H");
      break;
    case LD_L_L:
      instruction += tab + fmt::format("LD L, L");
      break;
    case LD_L_AHL:
      instruction += tab + fmt::format("LD L, (HL)");
      break;
    case LD_L_A:
      instruction += tab + fmt::format("LD L, A");
      break;

    case LD_AHL_B:
      instruction += tab + fmt::format("LD (HL), B");
      break;
    case LD_AHL_C:
      instruction += tab + fmt::format("LD (HL), C");
      break;
    case LD_AHL_D:
      instruction += tab + fmt::format("LD (HL), D");
      break;
    case LD_AHL_E:
      instruction += tab + fmt::format("LD (HL), E");
      break;
    case LD_AHL_H:
      instruction += tab + fmt::format("LD (HL), H");
      break;
    case LD_AHL_L:
      instruction += tab + fmt::format("LD (HL), L");
      break;
    case LD_AHL_A:
      instruction += tab + fmt::format("LD (HL), A");
      break;

    case LD_A_B:
      instruction += tab + fmt::format("LD A, B");
      break;
    case LD_A_C:
      instruction += tab + fmt::format("LD A, C");
      break;
    case LD_A_D:
      instruction += tab + fmt::format("LD A, D");
      break;
    case LD_A_E:
      instruction += tab + fmt::format("LD A, E");
      break;
    case LD_A_H:
      instruction += tab + fmt::format("LD A, H");
      break;
    case LD_A_L:
      instruction += tab + fmt::format("LD A, L");
      break;
    case LD_A_AHL:
      instruction += tab + fmt::format("LD A, (HL)");
      break;
    case LD_A_A:
      instruction += tab + fmt::format("LD A, A");
      break;

    case LD_AC_A:
      instruction += tab + fmt::format("LD (C), A");
      break;
    case LD_A_AC:
      instruction += tab + fmt::format("LD A, (C)");
      break;
    case LD_A16_A:
      instruction += fmt::format("{1:02x} {0:02x}{2}LD ({0:02x}{1:02x}), A",
                                 memory[addr++], memory[addr++], tab);
      break;
    case LD_A_A16:
      instruction += fmt::format("{1:02x} {0:02x}{2}LD A, ({0:02x}{1:02x})",
                                 memory[addr++], memory[addr++], tab);
      break;

    case LD_BC_D16:
      instruction += fmt::format("{1:02x} {0:02x}{2}LD BC, {0:02x}{1:02}",
                                 memory[addr++], memory[addr++], tab);
      break;
    case LD_DE_D16:
      instruction += fmt::format("{1:02x} {0:02x}{2}LD DE, {0:02x}{1:02}",
                                 memory[addr++], memory[addr++], tab);
      break;
    case LD_HL_D16:
      instruction += fmt::format("{1:02x} {0:02x}{2}LD HL, {0:02x}{1:02}",
                                 memory[addr++], memory[addr++], tab);
      break;
    case LD_SP_D16:
      instruction += fmt::format("{1:02x} {0:02x}{2}LD SP, {0:02x}{1:02x}",
                                 memory[addr++], memory[addr++], tab);
      break;
    case LD_A16_SP:
      instruction += fmt::format("{1:02x} {0:02x}{2}LD {0:02x}{1:02x}, SP",
                                 memory[addr++], memory[addr++], tab);
      break;
    case LD_SP_HL:
      instruction += tab + fmt::format("LD SP, HL");
      break;
    case LD_HL_SP_R8:
      instruction +=
          fmt::format("{0:02x}{1}LD HL, SP + {0:02x}", memory[addr++], tab);
      break;

    case LD_B_D8:
      instruction +=
          fmt::format("{0:02x}{1}LD B, {0:02x}", memory[addr++], tab);
      break;
    case LD_C_D8:
      instruction +=
          fmt::format("{0:02x}{1}LD C, {0:02x}", memory[addr++], tab);
      break;
    case LD_D_D8:
      instruction +=
          fmt::format("{0:02x}{1}LD D, {0:02x}", memory[addr++], tab);
      break;
    case LD_E_D8:
      instruction +=
          fmt::format("{0:02x}{1}LD E, {0:02x}", memory[addr++], tab);
      break;
    case LD_H_D8:
      instruction +=
          fmt::format("{0:02x}{1}LD H, {0:02x}", memory[addr++], tab);
      break;
    case LD_L_D8:
      instruction +=
          fmt::format("{0:02x}{1}LD L, {0:02x}", memory[addr++], tab);
      break;
    case LD_AHL_D8:
      instruction +=
          fmt::format("{0:02x}{1}LD (HL), {0:02x}", memory[addr++], tab);
      break;
    case LD_A_D8:
      instruction +=
          fmt::format("{0:02x}{1}LD A, {0:02x}", memory[addr++], tab);
      break;

    case RLCA:
      instruction += tab + fmt::format("RLCA");
      break;
    case RLA:
      instruction += tab + fmt::format("RLA");
      break;
    case RRCA:
      instruction += tab + fmt::format("RRCA");
      break;
    case RRA:
      instruction += tab + fmt::format("RRA");
      break;

    case RST_00:
      instruction += tab + fmt::format("RST 00H");
      break;
    case RST_10:
      instruction += tab + fmt::format("RST 10H");
      break;
    case RST_20:
      instruction += tab + fmt::format("RST 20H");
      break;
    case RST_30:
      instruction += tab + fmt::format("RST 30H");
      break;
    case RST_08:
      instruction += tab + fmt::format("RST 08H");
      break;
    case RST_18:
      instruction += tab + fmt::format("RST 18H");
      break;
    case RST_28:
      instruction += tab + fmt::format("RST 28H");
      break;
    case RST_38:
      instruction += tab + fmt::format("RST 38H");
      break;

    case INC_BC:
      instruction += tab + fmt::format("INC BC");
      break;
    case INC_DE:
      instruction += tab + fmt::format("INC DE");
      break;
    case INC_HL:
      instruction += tab + fmt::format("INC HL");
      break;
    case INC_SP:
      instruction += tab + fmt::format("INC SP");
      break;

    case JP_NZ_A16:
      instruction += fmt::format("{1:02x} {0:02x}{2}JP NZ, {0:02x}{1:02x}",
                                 memory[addr++], memory[addr++], tab);
      break;
    case JP_NC_A16:
      instruction += fmt::format("{1:02x} {0:02x}{2}JP NC, {0:02x}{1:02x}",
                                 memory[addr++], memory[addr++], tab);
      break;
    case JP_Z_A16:
      instruction += fmt::format("{1:02x} {0:02x}{2}JP Z, {0:02x}{1:02x}",
                                 memory[addr++], memory[addr++], tab);
      break;
    case JP_C_A16:
      instruction += fmt::format("{1:02x} {0:02x}{2}JP C, {0:02x}{1:02x}",
                                 memory[addr++], memory[addr++], tab);
      break;
    case JP_A16:
      instruction += fmt::format("{1:02x} {0:02x}{2}JP {0:02x}{1:02x}",
                                 memory[addr++], memory[addr++], tab);
      break;
    case JP_HL:
      instruction += tab + fmt::format("JP HL");
      break;

    default:
      instruction += tab + fmt::format("<undefined {:02x}>", opcode);
      break;
  }
  return instruction;
}
}  // namespace gb