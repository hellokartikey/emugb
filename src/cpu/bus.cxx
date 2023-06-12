#include "bus.hxx"

gb::Bus::Bus() {
    data = 0;
    addr = 0;
    read = true;
}

bool gb::Bus::read_signal() {
    return read;
}

void gb::Bus::set_write() {
    read = false;
}

void gb::Bus::set_read() {
    read = true;
}

void gb::Bus::write_addr(word addr) {
    this->addr = addr;
}

gb::word gb::Bus::read_addr() {
    return addr;
}

void gb::Bus::write_data(byte data) {
    this->data = data;
}

gb::byte gb::Bus::read_data() {
    return data;
}
