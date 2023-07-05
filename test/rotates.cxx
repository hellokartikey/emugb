#include <gtest/gtest.h>

#include "fixture.hxx"

using Opcode_Rotates_Test = CPUTest;

using namespace gb;

TEST_F(Opcode_Rotates_Test, RLCA_Test) {
    /** start - inline program */
    memory_t program = {
        LD_A_D8, 0x85,
        RLCA
    };
    memory.load_memory(program);
    cycles_t steps = 3;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();

    EXPECT_EQ(regs.A, 0x0A);
    EXPECT_EQ(regs.z, 0);
    EXPECT_EQ(regs.n, 0);
    EXPECT_EQ(regs.h, 0);
    EXPECT_EQ(regs.c, 1);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_Rotates_Test, RRCA_Test) {
    /** start - inline program */
    memory_t program = {
        LD_A_D8, 0x3b,
        RRCA
    };
    memory.load_memory(program);
    cycles_t steps = 3;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();

    EXPECT_EQ(regs.A, 0x9d);
    EXPECT_EQ(regs.z, 0);
    EXPECT_EQ(regs.n, 0);
    EXPECT_EQ(regs.h, 0);
    EXPECT_EQ(regs.c, 1);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_Rotates_Test, RLA_Test) {
    /** start - inline program */
    memory_t program = {
        LD_A_D8, 0x80,
        RLCA,
        LD_A_D8, 0x95,
        RLA
    };
    memory.load_memory(program);
    cycles_t steps = 6;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();

    EXPECT_EQ(regs.A, 0x2b);
    EXPECT_EQ(regs.z, 0);
    EXPECT_EQ(regs.n, 0);
    EXPECT_EQ(regs.h, 0);
    EXPECT_EQ(regs.c, 1);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_Rotates_Test, RRA_Test) {
    /** start - inline program */
    memory_t program = {
        LD_A_D8, 0x81,
        RRA
    };
    memory.load_memory(program);
    cycles_t steps = 3;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();

    EXPECT_EQ(regs.A, 0x40);
    EXPECT_EQ(regs.z, 0);
    EXPECT_EQ(regs.n, 0);
    EXPECT_EQ(regs.h, 0);
    EXPECT_EQ(regs.c, 1);
    EXPECT_EQ(steps, cpu.get_cycles());
}
