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
        if (0xE000 <= addr && addr < 0xFE00) {
            continue;
        }
        random_values[addr] = std::rand() % gb::max_byte;
        bus.write_addr(addr);
        bus.write_data(random_values[addr]);
        memory.read_bus();
    }

    bus.set_read();
    for (gb::word addr = 0x0000; addr < memory.size(); addr++) {
        if (0xE000 <= addr && addr < 0xFE00) {
            continue;
        }
        bus.write_addr(addr);
        memory.read_bus();
        EXPECT_EQ(bus.read_data(), random_values[addr]);
    }
}

TEST_F(MemoryTest, EchoMemoryForwardTest) {
    std::array<gb::byte, 0x1E00> echo_test;
    for (auto& byte: echo_test) {
        byte = std::rand() % gb::max_byte;
    }
    bus.set_write();
    for (gb::word addr = 0xC000; addr < 0xDE00; addr++) {
        bus.write_addr(addr);
        bus.write_data(echo_test[addr - 0xC000]);
        memory.read_bus();
    }
    bus.set_read();
    for (gb::word addr = 0xE000; addr < 0xFE00; addr++) {
        bus.write_addr(addr);
        memory.read_bus();
        EXPECT_EQ(bus.read_data(), echo_test[addr - 0xE000]);
    }
}

TEST_F(MemoryTest, EchoMemoryBackwardTest) {
    std::array<gb::byte, 0x1E00> echo_test;
    for (auto& byte: echo_test) {
        byte = std::rand() % gb::max_byte;
    }
    bus.set_write();
    for (gb::word addr = 0xE000; addr < 0xFE00; addr++) {
        bus.write_addr(addr);
        bus.write_data(echo_test[addr - 0xE000]);
        memory.read_bus();
    }
    bus.set_read();
    for (gb::word addr = 0xC000; addr < 0xDE00; addr++) {
        bus.write_addr(addr);
        memory.read_bus();
        EXPECT_EQ(bus.read_data(), echo_test[addr - 0xC000]);
    }
}

TEST_F(MemoryTest, LoadProgramTest) {
    gb::memory program;
    for (gb::word addr = 0x0000; addr < memory.size(); addr++) {
        program[addr] = (std::rand() % gb::max_byte);
    }
    memory.load_memory(program);

    bus.set_read();
    for (gb::word addr = 0x0000; addr < memory.size(); addr++) {
        bus.write_addr(addr);
        memory.read_bus();
        EXPECT_EQ(bus.read_data(), program[addr]);
    }
}
