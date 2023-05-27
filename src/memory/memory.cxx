#include "memory.hxx"

byte Memory::read(word addr) {
    if (addr < 0x0000 && addr > 0xffff) {
        return 0;
    }
    return 0;
}

void Memory::write(word addr, byte data) {
    memory[addr] = data;
}
