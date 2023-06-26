#include <gtest/gtest.h>

#include "fixture.hxx"

using Opcode_LD_A_A8_Test = CPUTest;

using namespace gb;

TEST_F(Opcode_LD_A_A8_Test, LDH_A8_A_Test) {
    /** start - inline program */
    memory_t program = {
        LD_A_D8, 0xab,
        LDH_A8_A, 0x12
    };
    memory.load_memory(program);
    cycles_t steps = 5;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(mem[0xff12], 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_A_A8_Test, LDH_A_A8_Test) {
    /** start - inline program */
    memory_t program = {
        LD_A_D8, 0xab,
        LDH_A8_A, 0x12,
        LD_A_D8, 0x00,
        LDH_A_A8, 0x12
    };
    memory.load_memory(program);
    cycles_t steps = 10;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();

    EXPECT_EQ(regs.A, 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_A_A8_Test, LD_AC_A_Test) {
    /** start - inline program */
    memory_t program = {
        LD_A_D8, 0xab,
        LD_C_D8, 0x12,
        LD_AC_A
    };
    memory.load_memory(program);
    cycles_t steps = 6;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(mem[0xff12], 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_A_A8_Test, LD_A_AC_Test) {
    /** start - inline program */
    memory_t program = {
        LD_A_D8, 0xab,
        LD_C_D8, 0x12,
        LD_AC_A,
        LD_A_D8, 0x00,
        LD_A_AC
    };
    memory.load_memory(program);
    cycles_t steps = 10;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();

    EXPECT_EQ(regs.A, 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_A_A8_Test, LD_A16_A_Test) {
    /** start - inline program */
    memory_t program = {
        LD_A_D8, 0xab,
        LD_A16_A, 0x34, 0x12
    };
    memory.load_memory(program);
    cycles_t steps = 6;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(mem[0x1234], 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_LD_A_A8_Test, LD_A_A16_Test) {
    /** start - inline program */
    memory_t program = {
        LD_A_D8, 0xab,
        LD_A16_A, 0x34, 0x12,
        LD_A_D8, 0x00,
        LD_A_A16, 0x34, 0x12
    };
    memory.load_memory(program);
    cycles_t steps = 12;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();

    EXPECT_EQ(regs.A, 0xab);
    EXPECT_EQ(steps, cpu.get_cycles());
}
