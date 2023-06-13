#include "memory.hxx"

gb::Memory::Memory(Bus& bus) : bus(bus) {
    memory = {0};
}

void gb::Memory::read_bus() {
    word addr = bus.read_addr();

    if (bus.read_signal()) {
        bus.write_data(memory[addr]);
        return;
    }

    memory[addr] = bus.read_data();
    if (0xE000 <= addr && addr < 0xFE00) {
        memory[addr - 0x2000] = bus.read_data();
    }
    if (0xC000 <= addr && addr < 0xDE00) {
        memory[addr + 0x2000] = bus.read_data();
    }
}

void gb::Memory::load_memory(gb::memory memory) {
    this->memory = memory;
}
