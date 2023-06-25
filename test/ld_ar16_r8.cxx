#include <gtest/gtest.h>

#include "fixture.hxx"

using Opcode_LD_AR16_Test = CPUTest;

using namespace gb;

TEST_F(Opcode_LD_AR16_Test, LD_AHL_B_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_HL_D16, 0x34, 0x12,
        LD_B_D8, 0xab,
        LD_AHL_B
    };
    memory.load_memory(program);
    cycles_t steps = 7;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(mem[0x1234], 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_AR16_Test, LD_AHL_C_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_HL_D16, 0x34, 0x12,
        LD_C_D8, 0xab,
        LD_AHL_C
    };
    memory.load_memory(program);
    cycles_t steps = 7;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(mem[0x1234], 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_AR16_Test, LD_AHL_D_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_HL_D16, 0x34, 0x12,
        LD_D_D8, 0xab,
        LD_AHL_D
    };
    memory.load_memory(program);
    cycles_t steps = 7;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(mem[0x1234], 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_AR16_Test, LD_AHL_E_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_HL_D16, 0x34, 0x12,
        LD_E_D8, 0xab,
        LD_AHL_E
    };
    memory.load_memory(program);
    cycles_t steps = 7;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(mem[0x1234], 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_AR16_Test, LD_AHL_H_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_HL_D16, 0x34, 0x12,
        LD_AHL_H
    };
    memory.load_memory(program);
    cycles_t steps = 5;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(mem[0x1234], 0x12);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_AR16_Test, LD_AHL_L_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_HL_D16, 0x34, 0x12,
        LD_AHL_L
    };
    memory.load_memory(program);
    cycles_t steps = 5;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(mem[0x1234], 0x34);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_AR16_Test, LD_AHL_A_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_HL_D16, 0x34, 0x12,
        LD_A_D8, 0xab,
        LD_AHL_A
    };
    memory.load_memory(program);
    cycles_t steps = 7;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(mem[0x1234], 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_AR16_Test, LD_ABC_A_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_BC_D16, 0x34, 0x12,
        LD_A_D8, 0xab,
        LD_ABC_A
    };
    memory.load_memory(program);
    cycles_t steps = 7;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(mem[regs.BC], 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_AR16_Test, LD_ADE_A_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_DE_D16, 0x34, 0x12,
        LD_A_D8, 0xab,
        LD_ADE_A
    };
    memory.load_memory(program);
    cycles_t steps = 7;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(mem[regs.DE], 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_AR16_Test, LD_AHLP_A_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_HL_D16, 0x34, 0x12,
        LD_A_D8, 0xab,
        LD_AHLP_A
    };
    memory.load_memory(program);
    cycles_t steps = 7;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(mem[0x1234], 0xab);
    EXPECT_EQ(regs.HL, 0x1235);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_AR16_Test, LD_AHLM_A_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_HL_D16, 0x34, 0x12,
        LD_A_D8, 0xab,
        LD_AHLM_A
    };
    memory.load_memory(program);
    cycles_t steps = 7;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(mem[0x1234], 0xab);
    EXPECT_EQ(regs.HL, 0x1233);
    EXPECT_EQ(steps, cpu.get_cycles());
}
