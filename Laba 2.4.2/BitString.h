#pragma once
#include <iostream>

const int MAX_BITS = 100;

class BitString {
private:

    unsigned char bits[MAX_BITS];
    int size;

public:
    BitString();
    BitString(const int& _size);
    BitString(const char* bitStr);
    BitString(const BitString& other);

    void setBit(const int& index, const unsigned char& value);
    unsigned char getBit(const int& index) const;
    int getSize() const;

    BitString operator&(const BitString& other) const;
    BitString operator|(const BitString& other) const;
    BitString operator^(const BitString& other) const;
    BitString operator~() const;
    BitString operator<<(const int& shift) const;
    BitString operator>>(const int& shift) const;

    friend std::ostream& operator<<(std::ostream& os, const BitString& bitStr);
    friend std::istream& operator>>(std::istream& is, BitString& bitStr);
};

