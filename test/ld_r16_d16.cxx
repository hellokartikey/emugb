#include <gtest/gtest.h>

#include "fixture.hxx"

using Opcode_LD_R16_D16_Test = CPUTest;

using namespace gb;

TEST_F(Opcode_LD_R16_D16_Test, LD_BC_D16_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_BC_D16, 0xcd, 0xab
    };
    memory.load_memory(program);
    cycles_t steps = 3;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();

    EXPECT_EQ(regs.BC, 0xABCD);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_R16_D16_Test, LD_DE_D16_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_DE_D16, 0xcd, 0xab
    };
    memory.load_memory(program);
    cycles_t steps = 3;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();

    EXPECT_EQ(regs.DE, 0xABCD);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_R16_D16_Test, LD_HL_D16_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_HL_D16, 0xcd, 0xab
    };
    memory.load_memory(program);
    cycles_t steps = 3;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();

    EXPECT_EQ(regs.HL, 0xABCD);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_R16_D16_Test, LD_SP_D16_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_SP_D16, 0xcd, 0xab
    };
    memory.load_memory(program);
    cycles_t steps = 3;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();

    EXPECT_EQ(regs.SP, 0xABCD);
    EXPECT_EQ(steps, cpu.get_cycles());
}
