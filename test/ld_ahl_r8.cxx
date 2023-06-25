#include <gtest/gtest.h>

#include "fixture.hxx"

using Opcode_LD_AHL_Test = CPUTest;

using namespace gb;

TEST_F(Opcode_LD_AHL_Test, LD_AHL_B_Test) {
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

    EXPECT_EQ(mem[regs.HL], 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_AHL_Test, LD_AHL_C_Test) {
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

    EXPECT_EQ(mem[regs.HL], 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_AHL_Test, LD_AHL_D_Test) {
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

    EXPECT_EQ(mem[regs.HL], 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_AHL_Test, LD_AHL_E_Test) {
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

    EXPECT_EQ(mem[regs.HL], 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_AHL_Test, LD_AHL_H_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_HL_D16, 0x34, 0x12,
        LD_H_D8, 0xab,
        LD_AHL_H
    };
    memory.load_memory(program);
    cycles_t steps = 7;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(mem[regs.HL], 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_AHL_Test, LD_AHL_L_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_HL_D16, 0x34, 0x12,
        LD_L_D8, 0xab,
        LD_AHL_L
    };
    memory.load_memory(program);
    cycles_t steps = 7;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(mem[regs.HL], 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_AHL_Test, LD_AHL_A_Test) {
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

    EXPECT_EQ(mem[regs.HL], 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}
