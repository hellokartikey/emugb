#include "memory.hxx"

Memory::Memory() {
    memory = {0};
}

byte Memory::read(word addr) {
    if (addr < 0x0000 && addr > 0xffff) {
        return 0;
    }
    return memory[addr];
}

void Memory::write(word addr, byte data) {
    memory[addr] = data;
}
