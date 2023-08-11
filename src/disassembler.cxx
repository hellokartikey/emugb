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

  std::string inst_addr = fmt::format("{:04x}", addr);
  std::string inst_opcode = "";
  std::string inst_mnemonic = "";

  byte opcode = memory[addr++];
  inst_opcode += fmt::format("{:02x} ", opcode);

  switch (opcode) {
    case NOP:
      inst_mnemonic = fmt::format("NOP");
      break;
    case STOP:
      inst_mnemonic = fmt::format("STOP");
      break;
    case HALT:
      inst_mnemonic = fmt::format("HALT");
      break;
    case DI:
      inst_mnemonic = fmt::format("DI");
      break;
    case EI:
      inst_mnemonic = fmt::format("EI");
      break;

    case LD_B_B:
      inst_mnemonic = fmt::format("LD B, B");
      break;
    case LD_B_C:
      inst_mnemonic = fmt::format("LD B, C");
      break;
    case LD_B_D:
      inst_mnemonic = fmt::format("LD B, D");
      break;
    case LD_B_E:
      inst_mnemonic = fmt::format("LD B, E");
      break;
    case LD_B_H:
      inst_mnemonic = fmt::format("LD B, H");
      break;
    case LD_B_L:
      inst_mnemonic = fmt::format("LD B, L");
      break;
    case LD_B_AHL:
      inst_mnemonic = fmt::format("LD B, (HL)");
      break;
    case LD_B_A:
      inst_mnemonic = fmt::format("LD B, A");
      break;

    case LD_C_B:
      inst_mnemonic = fmt::format("LD C, B");
      break;
    case LD_C_C:
      inst_mnemonic = fmt::format("LD C, C");
      break;
    case LD_C_D:
      inst_mnemonic = fmt::format("LD C, D");
      break;
    case LD_C_E:
      inst_mnemonic = fmt::format("LD C, E");
      break;
    case LD_C_H:
      inst_mnemonic = fmt::format("LD C, H");
      break;
    case LD_C_L:
      inst_mnemonic = fmt::format("LD C, L");
      break;
    case LD_C_AHL:
      inst_mnemonic = fmt::format("LD C, (HL)");
      break;
    case LD_C_A:
      inst_mnemonic = fmt::format("LD C, A");
      break;

    case LD_D_B:
      inst_mnemonic = fmt::format("LD D, B");
      break;
    case LD_D_C:
      inst_mnemonic = fmt::format("LD D, C");
      break;
    case LD_D_D:
      inst_mnemonic = fmt::format("LD D, D");
      break;
    case LD_D_E:
      inst_mnemonic = fmt::format("LD D, E");
      break;
    case LD_D_H:
      inst_mnemonic = fmt::format("LD D, H");
      break;
    case LD_D_L:
      inst_mnemonic = fmt::format("LD D, L");
      break;
    case LD_D_AHL:
      inst_mnemonic = fmt::format("LD D, (HL)");
      break;
    case LD_D_A:
      inst_mnemonic = fmt::format("LD D, A");
      break;

    case LD_E_B:
      inst_mnemonic = fmt::format("LD E, B");
      break;
    case LD_E_C:
      inst_mnemonic = fmt::format("LD E, C");
      break;
    case LD_E_D:
      inst_mnemonic = fmt::format("LD E, D");
      break;
    case LD_E_E:
      inst_mnemonic = fmt::format("LD E, E");
      break;
    case LD_E_H:
      inst_mnemonic = fmt::format("LD E, H");
      break;
    case LD_E_L:
      inst_mnemonic = fmt::format("LD E, L");
      break;
    case LD_E_AHL:
      inst_mnemonic = fmt::format("LD E, (HL)");
      break;
    case LD_E_A:
      inst_mnemonic = fmt::format("LD E, A");
      break;

    case LD_H_B:
      inst_mnemonic = fmt::format("LD H, B");
      break;
    case LD_H_C:
      inst_mnemonic = fmt::format("LD H, C");
      break;
    case LD_H_D:
      inst_mnemonic = fmt::format("LD H, D");
      break;
    case LD_H_E:
      inst_mnemonic = fmt::format("LD H, E");
      break;
    case LD_H_H:
      inst_mnemonic = fmt::format("LD H, H");
      break;
    case LD_H_L:
      inst_mnemonic = fmt::format("LD H, L");
      break;
    case LD_H_AHL:
      inst_mnemonic = fmt::format("LD H, (HL)");
      break;
    case LD_H_A:
      inst_mnemonic = fmt::format("LD H, A");
      break;

    case LD_L_B:
      inst_mnemonic = fmt::format("LD L, B");
      break;
    case LD_L_C:
      inst_mnemonic = fmt::format("LD L, C");
      break;
    case LD_L_D:
      inst_mnemonic = fmt::format("LD L, D");
      break;
    case LD_L_E:
      inst_mnemonic = fmt::format("LD L, E");
      break;
    case LD_L_H:
      inst_mnemonic = fmt::format("LD L, H");
      break;
    case LD_L_L:
      inst_mnemonic = fmt::format("LD L, L");
      break;
    case LD_L_AHL:
      inst_mnemonic = fmt::format("LD L, (HL)");
      break;
    case LD_L_A:
      inst_mnemonic = fmt::format("LD L, A");
      break;

    case LD_AHL_B:
      inst_mnemonic = fmt::format("LD (HL), B");
      break;
    case LD_AHL_C:
      inst_mnemonic = fmt::format("LD (HL), C");
      break;
    case LD_AHL_D:
      inst_mnemonic = fmt::format("LD (HL), D");
      break;
    case LD_AHL_E:
      inst_mnemonic = fmt::format("LD (HL), E");
      break;
    case LD_AHL_H:
      inst_mnemonic = fmt::format("LD (HL), H");
      break;
    case LD_AHL_L:
      inst_mnemonic = fmt::format("LD (HL), L");
      break;
    case LD_AHL_A:
      inst_mnemonic = fmt::format("LD (HL), A");
      break;

    case LD_A_B:
      inst_mnemonic = fmt::format("LD A, B");
      break;
    case LD_A_C:
      inst_mnemonic = fmt::format("LD A, C");
      break;
    case LD_A_D:
      inst_mnemonic = fmt::format("LD A, D");
      break;
    case LD_A_E:
      inst_mnemonic = fmt::format("LD A, E");
      break;
    case LD_A_H:
      inst_mnemonic = fmt::format("LD A, H");
      break;
    case LD_A_L:
      inst_mnemonic = fmt::format("LD A, L");
      break;
    case LD_A_AHL:
      inst_mnemonic = fmt::format("LD A, (HL)");
      break;
    case LD_A_A:
      inst_mnemonic = fmt::format("LD A, A");
      break;

    case LD_AC_A:
      inst_mnemonic = fmt::format("LD (C), A");
      break;
    case LD_A_AC:
      inst_mnemonic = fmt::format("LD A, (C)");
      break;
    case LD_A16_A:
      inst_opcode +=
          fmt::format("{:02x} {:02x}", memory[addr], memory[addr + 1]);
      inst_mnemonic +=
          fmt::format("LD ({0:02x}{1:02x}), A", memory[addr++], memory[addr++]);
      break;
    case LD_A_A16:
      inst_opcode +=
          fmt::format("{:02x} {:02x}", memory[addr], memory[addr + 1]);
      inst_mnemonic +=
          fmt::format("LD A, ({0:02x}{1:02x})", memory[addr++], memory[addr++]);
      break;

    case LD_BC_D16:
      inst_opcode +=
          fmt::format("{:02x} {:02x}", memory[addr], memory[addr + 1]);
      inst_mnemonic +=
          fmt::format("LD BC, {0:02x}{1:02x}", memory[addr++], memory[addr++]);
      break;
    case LD_DE_D16:
      inst_opcode +=
          fmt::format("{:02x} {:02x}", memory[addr], memory[addr + 1]);
      inst_mnemonic +=
          fmt::format("LD DE, {0:02x}{1:02x}", memory[addr++], memory[addr++]);
      break;
    case LD_HL_D16:
      inst_opcode +=
          fmt::format("{:02x} {:02x}", memory[addr], memory[addr + 1]);
      inst_mnemonic +=
          fmt::format("LD HL, {0:02x}{1:02x}", memory[addr++], memory[addr++]);
      break;
    case LD_SP_D16:
      inst_opcode +=
          fmt::format("{:02x} {:02x}", memory[addr], memory[addr + 1]);
      inst_mnemonic +=
          fmt::format("LD SP, {0:02x}{1:02x}", memory[addr++], memory[addr++]);
      break;
    case LD_A16_SP:
      inst_opcode +=
          fmt::format("{:02x} {:02x}", memory[addr], memory[addr + 1]);
      inst_mnemonic +=
          fmt::format("LD {0:02x}{1:02x}, SP", memory[addr++], memory[addr++]);
      break;
    case LD_SP_HL:
      inst_mnemonic = fmt::format("LD SP, HL");
      break;
    case LD_HL_SP_R8:
      inst_opcode += fmt::format("{:02x} ", memory[addr]);
      inst_mnemonic += fmt::format("LD HL, SP + {0:02x}", memory[addr++]);
      break;
    case LD_ABC_A:
      inst_mnemonic = fmt::format("LD (BC) A");
      break;
    case LD_ADE_A:
      inst_mnemonic = fmt::format("LD (DE) A");
      break;
    case LD_AHLP_A:
      inst_mnemonic = fmt::format("LD (HL+) A");
      break;
    case LD_AHLM_A:
      inst_mnemonic = fmt::format("LD (HL-) A");
      break;
    case LD_A_ABC:
      inst_mnemonic = fmt::format("LD A (BC)");
      break;
    case LD_A_ADE:
      inst_mnemonic = fmt::format("LD A (DE)");
      break;
    case LD_A_AHLP:
      inst_mnemonic = fmt::format("LD A (HL+)");
      break;
    case LD_A_AHLM:
      inst_mnemonic = fmt::format("LD A (HL-)");
      break;

    case LD_B_D8:
      inst_opcode += fmt::format("{:02x} ", memory[addr]);
      inst_mnemonic += fmt::format("LD B, {0:02x}", memory[addr++]);
      break;
    case LD_C_D8:
      inst_opcode += fmt::format("{:02x} ", memory[addr]);
      inst_mnemonic += fmt::format("LD C, {0:02x}", memory[addr++]);
      break;
    case LD_D_D8:
      inst_opcode += fmt::format("{:02x} ", memory[addr]);
      inst_mnemonic += fmt::format("LD D, {0:02x}", memory[addr++]);
      break;
    case LD_E_D8:
      inst_opcode += fmt::format("{:02x} ", memory[addr]);
      inst_mnemonic += fmt::format("LD E, {0:02x}", memory[addr++]);
      break;
    case LD_H_D8:
      inst_opcode += fmt::format("{:02x} ", memory[addr]);
      inst_mnemonic += fmt::format("LD H, {0:02x}", memory[addr++]);
      break;
    case LD_L_D8:
      inst_opcode += fmt::format("{:02x} ", memory[addr]);
      inst_mnemonic += fmt::format("LD L, {0:02x}", memory[addr++]);
      break;
    case LD_AHL_D8:
      inst_opcode += fmt::format("{:02x} ", memory[addr]);
      inst_mnemonic += fmt::format("LD (HL), {0:02x}", memory[addr++]);
      break;
    case LD_A_D8:
      inst_opcode += fmt::format("{:02x} ", memory[addr]);
      inst_mnemonic += fmt::format("LD A, {0:02x}", memory[addr++]);
      break;

    case LDH_A8_A:
      inst_opcode += fmt::format("{:02x} ", memory[addr]);
      inst_mnemonic += fmt::format("LDH ({0:02x}), A", memory[addr++]);
      break;
    case LDH_A_A8:
      inst_opcode += fmt::format("{:02x} ", memory[addr]);
      inst_mnemonic += fmt::format("LDH A, ({0:02x})", memory[addr++]);
      break;

    case RLCA:
      inst_mnemonic = fmt::format("RLCA");
      break;
    case RLA:
      inst_mnemonic = fmt::format("RLA");
      break;
    case RRCA:
      inst_mnemonic = fmt::format("RRCA");
      break;
    case RRA:
      inst_mnemonic = fmt::format("RRA");
      break;

    case RST_00:
      inst_mnemonic = fmt::format("RST 00H");
      break;
    case RST_10:
      inst_mnemonic = fmt::format("RST 10H");
      break;
    case RST_20:
      inst_mnemonic = fmt::format("RST 20H");
      break;
    case RST_30:
      inst_mnemonic = fmt::format("RST 30H");
      break;
    case RST_08:
      inst_mnemonic = fmt::format("RST 08H");
      break;
    case RST_18:
      inst_mnemonic = fmt::format("RST 18H");
      break;
    case RST_28:
      inst_mnemonic = fmt::format("RST 28H");
      break;
    case RST_38:
      inst_mnemonic = fmt::format("RST 38H");
      break;

    case INC_BC:
      inst_mnemonic = fmt::format("INC BC");
      break;
    case INC_DE:
      inst_mnemonic = fmt::format("INC DE");
      break;
    case INC_HL:
      inst_mnemonic = fmt::format("INC HL");
      break;
    case INC_SP:
      inst_mnemonic = fmt::format("INC SP");
      break;

    case JP_NZ_A16:
      inst_opcode +=
          fmt::format("{:02x} {:02x}", memory[addr], memory[addr + 1]);
      inst_mnemonic +=
          fmt::format("JP NZ, {0:02x}{1:02x}", memory[addr++], memory[addr++]);
      break;
    case JP_NC_A16:
      inst_opcode +=
          fmt::format("{:02x} {:02x}", memory[addr], memory[addr + 1]);
      inst_mnemonic +=
          fmt::format("JP NC, {0:02x}{1:02x}", memory[addr++], memory[addr++]);
      break;
    case JP_Z_A16:
      inst_opcode +=
          fmt::format("{:02x} {:02x}", memory[addr], memory[addr + 1]);
      inst_mnemonic +=
          fmt::format("JP Z, {0:02x}{1:02x}", memory[addr++], memory[addr++]);
      break;
    case JP_C_A16:
      inst_opcode +=
          fmt::format("{:02x} {:02x}", memory[addr], memory[addr + 1]);
      inst_mnemonic +=
          fmt::format("JP C, {0:02x}{1:02x}", memory[addr++], memory[addr++]);
      break;
    case JP_A16:
      inst_opcode +=
          fmt::format("{:02x} {:02x}", memory[addr], memory[addr + 1]);
      inst_mnemonic +=
          fmt::format("JP {0:02x}{1:02x}", memory[addr++], memory[addr++]);
      break;
    case JP_AHL:
      inst_mnemonic = fmt::format("JP (HL)");
      break;

    case CALL_A16:
      inst_opcode +=
          fmt::format("{:02x} {:02x}", memory[addr], memory[addr + 1]);
      inst_mnemonic +=
          fmt::format("CALL {0:02x}{1:02x}", memory[addr++], memory[addr++]);
      break;

    case CPL:
      inst_mnemonic = fmt::format("CPL");
      break;
    case CCF:
      inst_mnemonic = fmt::format("CCF");
      break;

    default:
      inst_mnemonic = fmt::format("<undefined {:02x}>", opcode);
      break;
  }

  std::string instruction =
      inst_addr + " - " + inst_opcode + "\t- " + inst_mnemonic;
  return instruction;
}
}  // namespace gb