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
}

void gb::Memory::load_program(gb::program program, word start) {
    bus.set_write();
    for (auto& opcode: program) {
        bus.write_addr(start++);
        bus.write_data(opcode);
        read_bus();
    }
    bus.set_read();
}
