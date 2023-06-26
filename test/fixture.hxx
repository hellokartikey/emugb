#include <gtest/gtest.h>

#include "bus.hxx"
#include "memory.hxx"
#include "cpu.hxx"

class BusTest : public testing::Test {
protected:
    gb::Bus bus;
};

class MemoryTest : public testing::Test {
protected:
    gb::Bus bus;
    gb::Memory memory;

    MemoryTest() : memory(bus) {}
};

class CPUTest : public testing::Test {
protected:
    gb::Bus bus;
    gb::Memory memory;
    gb::CPU cpu;

    CPUTest() : memory(bus), cpu(bus, memory) {}
};
