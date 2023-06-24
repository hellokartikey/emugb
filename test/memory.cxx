#include <array>
#include <cstdlib>

#include <gtest/gtest.h>

#include "fixture.hxx"

TEST_F(MemoryTest, InitTest) {
    bus.set_read();
    for (gb::word addr = 0; addr < memory.size(); addr++) {
        bus.write_addr(addr);
        memory.read_bus();
        EXPECT_EQ(bus.read_data(), 0x00);
    }
}

TEST_F(MemoryTest, SizeTest) {
    EXPECT_EQ(memory.size(), gb::memory_size);
}

TEST_F(MemoryTest, ReadWriteTest) {
    gb::memory_t random_values;
    bus.set_write();
    for (gb::word addr = 0x0000; addr < memory.size(); addr++) {
        if (0xE000 <= addr && addr < 0xFE00) {
            continue;
        }

        random_values[addr] = gb::rand_byte();
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
        byte = gb::rand_byte();
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
        byte = gb::rand_byte();
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
    gb::memory_t program;
    for (gb::word addr = 0x0000; addr < memory.size(); addr++) {
        program[addr] = gb::rand_byte();
    }
    memory.load_memory(program);

    bus.set_read();
    for (gb::word addr = 0x0000; addr < memory.size(); addr++) {
        bus.write_addr(addr);
        memory.read_bus();
        EXPECT_EQ(bus.read_data(), program[addr]);
    }
}

TEST_F(MemoryTest, MemoryDumpTest) {
    gb::memory_t program;
    for (gb::word addr = 0x0000; addr < memory.size(); addr++) {
        program[addr] = gb::rand_byte();
    }
    memory.load_memory(program);

    gb::memory_t dump = memory.dump_memory();

    EXPECT_EQ(program, dump);
}
