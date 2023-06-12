#include <array>
#include <cstdlib>

#include <gtest/gtest.h>

#include "cpu/memory.hxx"
#include "cpu/bus.hxx"

class MemoryTest : public testing::Test {
protected:
    gb::Bus bus;
    gb::Memory memory;

    MemoryTest() : memory(bus) {}
};

TEST_F(MemoryTest, InitTest) {
    bus.set_read();
    for (gb::word addr = 0; addr < memory.size(); addr++) {
        bus.write_addr(addr);
        memory.read_bus();
        EXPECT_EQ(bus.read_data(), 0x00);
    }
}

TEST_F(MemoryTest, ReadWriteTest) {
    std::array<gb::byte, memory.size()> random_values;
    bus.set_write();
    for (gb::word addr = 0x0000; addr < memory.size(); addr++) {
        random_values[addr] = std::rand() % 0xFF;
        bus.write_addr(addr);
        bus.write_data(random_values[addr]);
        memory.read_bus();
    }

    bus.set_read();
    for (gb::word addr = 0x0000; addr < memory.size(); addr++) {
        bus.write_addr(addr);
        memory.read_bus();
        EXPECT_EQ(bus.read_data(), random_values[addr]);
    }
}

TEST_F(MemoryTest, LoadProgramTest) {
    gb::memory program;
    for (gb::word addr = 0x0000; addr < memory.size(); addr++) {
        program[addr] = (std::rand() % 0xFF);
    }
    memory.load_memory(program);

    bus.set_read();
    for (gb::word addr = 0x0000; addr < memory.size(); addr++) {
        bus.write_addr(addr);
        memory.read_bus();
        EXPECT_EQ(bus.read_data(), program[addr]);
    }
}
