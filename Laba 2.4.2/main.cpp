#include "BitString.h"

int main() {
    BitString bs1("101010");
    BitString bs2("110011");

    std::cout << "BitString 1: " << bs1 << std::endl;
    std::cout << "BitString 2: " << bs2 << std::endl;

    std::cout << "Bitwise AND: " << (bs1 & bs2) << std::endl;
    std::cout << "Bitwise OR: " << (bs1 | bs2) << std::endl;
    std::cout << "Bitwise XOR: " << (bs1 ^ bs2) << std::endl;
    std::cout << "Bitwise NOT for BitString 1: " << (~bs1) << std::endl;

    std::cout << "Left shift for BitString 2 by 2 bits: " << (bs2 << 2) << std::endl;
    std::cout << "Right shift for BitString 1 by 3 bits: " << (bs1 >> 3) << std::endl;

    return 0;
}