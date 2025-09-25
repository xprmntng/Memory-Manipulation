#include <iostream>
#include <iomanip>

#include "Memory.hpp"

int main() {
    int x = 5;
    Memory::address addr = Memory::decay(&x);
    std::cout << std::hex << addr << std::endl;
    Memory::hex_dump(std::cout, x);
    std::cout << Memory::to_hex_str(x) << std::endl;
}
