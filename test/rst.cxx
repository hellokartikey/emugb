#include <gtest/gtest.h>

#include "fixture.hxx"

using Opcode_RST_Test = CPUTest;

using namespace gb;

TEST_F(Opcode_RST_Test, RST_00_Test) {
    /** start - inline program */
    memory_t program = {
        LD_SP_D16, 0xfe, 0xff,
        RST_00
    };
    memory.load_memory(program);
    cycles_t steps = 7;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(regs.PC, 0x0000);
    EXPECT_EQ(regs.SP, 0xfffc);
    EXPECT_EQ(mem[regs.SP+1], 0x04);
    EXPECT_EQ(mem[regs.SP+2], 0x00);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_RST_Test, RST_08_Test) {
    /** start - inline program */
    memory_t program = {
        LD_SP_D16, 0xfe, 0xff,
        RST_08
    };
    memory.load_memory(program);
    cycles_t steps = 7;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(regs.PC, 0x0008);
    EXPECT_EQ(regs.SP, 0xfffc);
    EXPECT_EQ(mem[regs.SP+1], 0x04);
    EXPECT_EQ(mem[regs.SP+2], 0x00);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_RST_Test, RST_10_Test) {
    /** start - inline program */
    memory_t program = {
        LD_SP_D16, 0xfe, 0xff,
        RST_10
    };
    memory.load_memory(program);
    cycles_t steps = 7;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(regs.PC, 0x0010);
    EXPECT_EQ(regs.SP, 0xfffc);
    EXPECT_EQ(mem[regs.SP+1], 0x04);
    EXPECT_EQ(mem[regs.SP+2], 0x00);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_RST_Test, RST_18_Test) {
    /** start - inline program */
    memory_t program = {
        LD_SP_D16, 0xfe, 0xff,
        RST_18
    };
    memory.load_memory(program);
    cycles_t steps = 7;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(regs.PC, 0x0018);
    EXPECT_EQ(regs.SP, 0xfffc);
    EXPECT_EQ(mem[regs.SP+1], 0x04);
    EXPECT_EQ(mem[regs.SP+2], 0x00);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_RST_Test, RST_20_Test) {
    /** start - inline program */
    memory_t program = {
        LD_SP_D16, 0xfe, 0xff,
        RST_20
    };
    memory.load_memory(program);
    cycles_t steps = 7;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(regs.PC, 0x0020);
    EXPECT_EQ(regs.SP, 0xfffc);
    EXPECT_EQ(mem[regs.SP+1], 0x04);
    EXPECT_EQ(mem[regs.SP+2], 0x00);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_RST_Test, RST_28_Test) {
    /** start - inline program */
    memory_t program = {
        LD_SP_D16, 0xfe, 0xff,
        RST_28
    };
    memory.load_memory(program);
    cycles_t steps = 7;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(regs.PC, 0x0028);
    EXPECT_EQ(regs.SP, 0xfffc);
    EXPECT_EQ(mem[regs.SP+1], 0x04);
    EXPECT_EQ(mem[regs.SP+2], 0x00);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_RST_Test, RST_30_Test) {
    /** start - inline program */
    memory_t program = {
        LD_SP_D16, 0xfe, 0xff,
        RST_30
    };
    memory.load_memory(program);
    cycles_t steps = 7;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(regs.PC, 0x0030);
    EXPECT_EQ(regs.SP, 0xfffc);
    EXPECT_EQ(mem[regs.SP+1], 0x04);
    EXPECT_EQ(mem[regs.SP+2], 0x00);
    EXPECT_EQ(steps, cpu.get_cycles());
}

TEST_F(Opcode_RST_Test, RST_38_Test) {
    /** start - inline program */
    memory_t program = {
        LD_SP_D16, 0xfe, 0xff,
        RST_38
    };
    memory.load_memory(program);
    cycles_t steps = 7;
    /** end   - inline program */

    cpu.execute(steps);
    registers_t regs = cpu.get_regs();
    memory_t mem = memory.dump_memory();

    EXPECT_EQ(regs.PC, 0x0038);
    EXPECT_EQ(regs.SP, 0xfffc);
    EXPECT_EQ(mem[regs.SP+1], 0x04);
    EXPECT_EQ(mem[regs.SP+2], 0x00);
    EXPECT_EQ(steps, cpu.get_cycles());
}
