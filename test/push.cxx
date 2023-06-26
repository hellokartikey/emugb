#include <gtest/gtest.h>

#include "fixture.hxx"

using Opcode_PUSH_Test = CPUTest;

using namespace gb;

TEST_F(Opcode_PUSH_Test, PUSH_BC_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_SP_D16, 0xfe, 0xff,
        LD_BC_D16, 0xcd, 0xab,
        PUSH_BC
    };
    memory.load_memory(program);
    cycles_t steps = 10;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(steps, cpu.get_cycles());
    EXPECT_EQ(regs.SP, 0xfffc);
    EXPECT_EQ(mem[regs.SP+1], 0xcd);
    EXPECT_EQ(mem[regs.SP+2], 0xab);
}

TEST_F(Opcode_PUSH_Test, PUSH_DE_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_SP_D16, 0xfe, 0xff,
        LD_DE_D16, 0xcd, 0xab,
        PUSH_DE
    };
    memory.load_memory(program);
    cycles_t steps = 10;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(steps, cpu.get_cycles());
    EXPECT_EQ(regs.SP, 0xfffc);
    EXPECT_EQ(mem[regs.SP+1], 0xcd);
    EXPECT_EQ(mem[regs.SP+2], 0xab);
}

TEST_F(Opcode_PUSH_Test, PUSH_HL_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_SP_D16, 0xfe, 0xff,
        LD_HL_D16, 0xcd, 0xab,
        PUSH_HL
    };
    memory.load_memory(program);
    cycles_t steps = 10;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(steps, cpu.get_cycles());
    EXPECT_EQ(regs.SP, 0xfffc);
    EXPECT_EQ(mem[regs.SP+1], 0xcd);
    EXPECT_EQ(mem[regs.SP+2], 0xab);
}

TEST_F(Opcode_PUSH_Test, PUSH_AF_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        LD_SP_D16, 0xfe, 0xff,
        LD_A_D8, 0xab,
        PUSH_AF
    };
    memory.load_memory(program);
    cycles_t steps = 3+2+4;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(steps, cpu.get_cycles());
    EXPECT_EQ(regs.SP, 0xfffc);
    EXPECT_EQ(mem[regs.SP+1], 0x00);
    EXPECT_EQ(mem[regs.SP+2], 0xab);
}
