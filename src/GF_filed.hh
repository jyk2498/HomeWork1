 #ifndef GF_FILED_HH
#define GF_FIELD_HH

#include <iostream>

class GF_FIELD {
    public:
        // GF(2^8)에 해당하는 기약 다항식 하나를 선정하였다. (x^8 + x^6 + x^4 + x^3 + x^2 + x + 1)
        static const unsigned char value = 0x15F; // x^8 + x^6 + x^4 + x^3 + x^2 + x + 1 을 16진법으로 나타낸다.

};

class GF_ELEMENT {
    private:
        unsigned char value; // This will hold the value of the GF(2^8) element

        static unsigned char xtime(unsigned char x) {
            // This function multiplies by x in GF(2^8), reducing by the primitive polynomial if needed
            return (x & 0x80) ? (x << 1) ^ GF_FIELD::value : (x << 1);
        }

    public:
        GF_ELEMENT() : value(0) {}
        GF_ELEMENT(unsigned char v) : value(v) {}

        GF_ELEMENT operator+(const GF_ELEMENT& other) const {
            // Addition in GF(2^8) is just XOR
            return GF_ELEMENT(this->value ^ other.value);
        }

        GF_ELEMENT operator*(const GF_ELEMENT& other) const 
            // 곱하기 연산을 취하는 코드
            unsigned char a = this->value;
            unsigned char b = other.value;
            unsigned char p = 0;

            while (b) {
                if (b & 1) {
                    p ^= a;
                }
                a = xtime(a);
                b >>= 1;
            }

            return GF_ELEMENT(p);
        }

        unsigned char getValue() const {
            return value;
        }

        friend std::ostream& operator<<(std::ostream& os, const GF_ELEMENT& gf) {
            os << std::hex << (int)gf.value;
            return os;
        }
};
#endif
