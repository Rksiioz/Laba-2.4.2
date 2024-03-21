#include "BitString.h"
#include <cstring>

BitString::BitString() : size(0) {
    for (int i = 0; i < MAX_BITS; ++i)
        bits[i] = 0;
}

BitString::BitString(const int& _size) : size(_size) {
    if (_size > MAX_BITS || _size < 0) {
        std::cerr << "Invalid size specified!\n";
        exit(1);
    }
    for (int i = 0; i < size; ++i)
        bits[i] = 0;
}

BitString::BitString(const char* bitStr) {
    size = strlen(bitStr);
    if (size > MAX_BITS) {
        std::cerr << "Bit string exceeds maximum length!\n";
        exit(1);
    }
    for (int i = 0; i < size; ++i) {
        if (bitStr[i] == '0')
            bits[i] = 0;
        else if (bitStr[i] == '1')
            bits[i] = 1;
        else {
            std::cerr << "Invalid character in bit string!\n";
            exit(1);
        }
    }
}

BitString::BitString(const BitString& other) {
    size = other.size;
    for (int i = 0; i < size; ++i)
        bits[i] = other.bits[i];
}

void BitString::setBit(const int& index, const unsigned char& value) {
    if (index < 0 || index >= size) {
        std::cerr << "Invalid index!\n";
        exit(1);
    }
    if (value != 0 && value != 1) {
        std::cerr << "Invalid bit value!\n";
        exit(1);
    }
    bits[index] = value;
}

unsigned char BitString::getBit(const int& index) const {
    if (index < 0 || index >= size) {
        std::cerr << "Invalid index!\n";
        exit(1);
    }
    return bits[index];
}

int BitString::getSize() const {
    return size;
}

BitString BitString::operator&(const BitString& other) const {
    BitString result(std::min(size, other.size));
    for (int i = 0; i < result.size; ++i)
        result.bits[i] = bits[i] & other.bits[i];
    return result;
}

BitString BitString::operator|(const BitString& other) const {
    BitString result(std::max(size, other.size));
    for (int i = 0; i < size; ++i)
        result.bits[i] = bits[i];
    for (int i = 0; i < other.size; ++i)
        result.bits[i] |= other.bits[i];
    return result;
}

BitString BitString::operator^(const BitString& other) const {
    BitString result(std::max(size, other.size));
    for (int i = 0; i < size; ++i)
        result.bits[i] = bits[i];
    for (int i = 0; i < other.size; ++i)
        result.bits[i] ^= other.bits[i];
    return result;
}

BitString BitString::operator~() const {
    BitString result(size);
    for (int i = 0; i < size; ++i)
        result.bits[i] = !bits[i];
    return result;
}

BitString BitString::operator<<(const int& shift) const {
    BitString result(size);
    for (int i = 0; i < size - shift; ++i)
        result.bits[i] = bits[i + shift];
    for (int i = size - shift; i < size; ++i)
        result.bits[i] = 0;
    return result;
}

BitString BitString::operator>>(const int& shift) const {
    BitString result(size);
    for (int i = shift; i < size; ++i)
        result.bits[i] = bits[i - shift];
    for (int i = 0; i < shift; ++i)
        result.bits[i] = 0;
    return result;
}

std::ostream& operator<<(std::ostream& os, const BitString& bitStr) {
    for (int i = 0; i < bitStr.size; ++i)
        os << static_cast<int>(bitStr.bits[i]);
    return os;
}

std::istream& operator>>(std::istream& is, BitString& bitStr) {
    std::string input;
    is >> input;
    bitStr = BitString(input.c_str());
    return is;
}
