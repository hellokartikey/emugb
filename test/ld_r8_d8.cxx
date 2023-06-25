#include <gtest/gtest.h>

#include "fixture.hxx"

using Opcode_LD_X_D8_Test = CPUTest;

using namespace gb;

TEST_F(Opcode_LD_X_D8_Test, LD_B_D8_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_B_D8, 0xab
    };
    memory.load_memory(program);
    cycles_t steps = 2;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();

    EXPECT_EQ(regs.B, 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_X_D8_Test, LD_C_D8_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_C_D8, 0xab
    };
    memory.load_memory(program);
    cycles_t steps = 2;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();

    EXPECT_EQ(regs.C, 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_X_D8_Test, LD_D_D8_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_D_D8, 0xab
    };
    memory.load_memory(program);
    cycles_t steps = 2;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();

    EXPECT_EQ(regs.D, 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_X_D8_Test, LD_E_D8_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_E_D8, 0xab
    };
    memory.load_memory(program);
    cycles_t steps = 2;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();

    EXPECT_EQ(regs.E, 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_X_D8_Test, LD_H_D8_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_H_D8, 0xab
    };
    memory.load_memory(program);
    cycles_t steps = 2;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();

    EXPECT_EQ(regs.H, 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_X_D8_Test, LD_L_D8_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_L_D8, 0xab
    };
    memory.load_memory(program);
    cycles_t steps = 2;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();

    EXPECT_EQ(regs.L, 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_X_D8_Test, LD_AHL_D8_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_AHL_D8, 0xab
    };
    memory.load_memory(program);
    cycles_t steps = 3;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(mem[regs.HL], 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_X_D8_Test, LD_A_D8_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_HL_D16, 0x34, 0x12,
        LD_A_D8, 0xab
    };
    memory.load_memory(program);
    cycles_t steps = 5;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();

    EXPECT_EQ(regs.A, 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}
