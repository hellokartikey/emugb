#include <gtest/gtest.h>

#include "fixture.hxx"

using Opcode_POP_Test = CPUTest;

using namespace gb;

TEST_F(Opcode_POP_Test, POP_BC_Test) {
    /** start - inline program */
    memory_t program = {
        LD_SP_D16, 0xfe, 0xff,
        LD_BC_D16, 0xcd, 0xab,
        PUSH_BC,
        LD_BC_D16, 0x00, 0x00,
        POP_BC
    };
    memory.load_memory(program);
    cycles_t steps = 16;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(steps, cpu.get_cycles());
    EXPECT_EQ(regs.SP, 0xfffe);
    EXPECT_EQ(regs.BC, 0xabcd);
}

TEST_F(Opcode_POP_Test, POP_DE_Test) {
    /** start - inline program */
    memory_t program = {
        LD_SP_D16, 0xfe, 0xff,
        LD_BC_D16, 0xcd, 0xab,
        PUSH_BC,
        POP_DE
    };
    memory.load_memory(program);
    cycles_t steps = 13;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(steps, cpu.get_cycles());
    EXPECT_EQ(regs.SP, 0xfffe);
    EXPECT_EQ(regs.DE, 0xabcd);
}

TEST_F(Opcode_POP_Test, POP_HL_Test) {
    /** start - inline program */
    memory_t program = {
        LD_SP_D16, 0xfe, 0xff,
        LD_BC_D16, 0xcd, 0xab,
        PUSH_BC,
        POP_HL
    };
    memory.load_memory(program);
    cycles_t steps = 13;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(steps, cpu.get_cycles());
    EXPECT_EQ(regs.SP, 0xfffe);
    EXPECT_EQ(regs.HL, 0xabcd);
}

TEST_F(Opcode_POP_Test, POP_AF_Test) {
    /** start - inline program */
    memory_t program = {
        LD_SP_D16, 0xfe, 0xff,
        LD_BC_D16, 0xcd, 0xab,
        PUSH_BC,
        POP_AF
    };
    memory.load_memory(program);
    cycles_t steps = 13;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(steps, cpu.get_cycles());
    EXPECT_EQ(regs.SP, 0xfffe);
    EXPECT_EQ(regs.AF, 0xabcd);
}
