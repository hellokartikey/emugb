#include "memory.hxx"

gb::Memory::Memory(Bus& bus) : bus(bus) {
    memory = {0};
}

void gb::Memory::read_bus() {
    word addr = bus.read_addr();

    if (bus.read_signal()) {
        bus.write_data(read(addr));
        return;
    }

    byte data = bus.read_data();
    write(addr, data);
}

gb::byte gb::Memory::read(gb::word addr) {
    return memory[addr];
}

void gb::Memory::write(gb::word addr, gb::byte data) {
    memory[addr] = data;

    if (0xE000 <= addr && addr < 0xFE00) { memory[addr - 0x2000] = data; }
    if (0xC000 <= addr && addr < 0xDE00) { memory[addr + 0x2000] = data; }
}

void gb::Memory::load_memory(gb::memory_t memory) {
    this->memory = memory;
}

gb::memory_t gb::Memory::dump_memory() {
    return memory;
}
