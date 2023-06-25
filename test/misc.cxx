#include <gtest/gtest.h>

#include "fixture.hxx"

using OpcodeMiscTest = CPUTest;

using namespace gb;

TEST_F(OpcodeMiscTest, NOP_Test) {
    /** start - inline program */
    cpu.reset();
    memory_t program = {
        NOP
    };
    memory.load_memory(program);
    cycles_t steps = 1;
    /** end   - inline program */

    registers_t before = cpu.get_regs();
    cpu.execute(steps);
    registers_t after = cpu.get_regs();
    before.PC++;

    EXPECT_TRUE(regs_iseq(before, after));
    EXPECT_EQ(steps, cpu.get_cycles());
}
