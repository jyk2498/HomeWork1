#ifndef GF_FIELD_HH
#define GF_FIELD_HH

#include <cstdint>
#include <array> 

class GF_FIELD {
public:
    static const uint8_t irreducible_polynomial = 0x1B; // x^8 + x^4 + x^3 + x + 1
    static std::array<uint8_t, 256> exp_table;
    static std::array<uint8_t, 256> log_table;

    static void initialize_tables() {
        uint8_t x = 1;
        for (int i = 0; i < 255; ++i) {
            exp_table[i] = x;
            log_table[x] = i;
            x = multiply(x, 0x03); // 0x03은 GF(2^8)의 생성원
            if (x == 1) break; 
        }
        exp_table[255] = exp_table[0];
    }

    static uint8_t add(uint8_t a, uint8_t b) {
        return a ^ b; // GF(2^8)에서 덧셈은 XOR 연산과 동일
    }

    // GF(2^8)에서 뺄셈은 덧셈과 동일
    static uint8_t subtract(uint8_t a, uint8_t b) {
        return add(a, b); // 뺄셈도 XOR 연산을 사용
    }

    static uint8_t multiply(uint8_t a, uint8_t b) {
        uint8_t result = 0;
        while (a && b) {
            if (b & 1)
                result ^= a;
            if (a & 0x80)
                a = (a << 1) ^ irreducible_polynomial;
            else
                a <<= 1;
            b >>= 1;
        }
        return result;
    }

    static uint8_t inverse(uint8_t a) {
        if (a == 0) return 0; // 0의 역원은 정의되지 않음
        return exp_table[255 - log_table[a]];
    }

    static uint8_t divide(uint8_t a, uint8_t b) {
        // b의 역원을 찾고, a와 곱
        return multiply(a, inverse(b));
    }
};
std::array<uint8_t, 256> GF_FIELD::exp_table = {};
std::array<uint8_t, 256> GF_FIELD::log_table = {};

class GF_ELEMENT {
public:
    uint8_t value;

    GF_ELEMENT(uint8_t val = 0) : value(val) {}

    GF_ELEMENT operator+(const GF_ELEMENT& other) const {
        return GF_FIELD::add(value, other.value);
    }

    GF_ELEMENT operator-(const GF_ELEMENT& other) const {
        return GF_FIELD::subtract(value, other.value);
    }

    GF_ELEMENT operator*(const GF_ELEMENT& other) const {
        return GF_FIELD::multiply(value, other.value);
    }

    GF_ELEMENT operator/(const GF_ELEMENT& other) const {
        return GF_FIELD::divide(value, other.value);
    }
};

#endif