#include "GF_field.hh"
#include <stdexcept> 

// + 
GF_ELEMENT GF_ELEMENT::operator+(const GF_ELEMENT& other) const {
    return GF_ELEMENT((this->value + other.value) % GF_FIELD::get_size());
}

// - 
GF_ELEMENT GF_ELEMENT::operator-(const GF_ELEMENT& other) const {
    return GF_ELEMENT((this->value - other.value + GF_FIELD::get_size()) % GF_FIELD::get_size());
}

// * 
GF_ELEMENT GF_ELEMENT::operator*(const GF_ELEMENT& other) const {
    return GF_ELEMENT((this->value * other.value) % GF_FIELD::get_size());
}

// / 
GF_ELEMENT GF_ELEMENT::operator/(const GF_ELEMENT& other) const {
    int b = other.value;
    int gf = GF_FIELD::get_size();
    int result = -1;
    for (int i = 1; i < gf; i++) {
        if ((b * i) % gf == 1) {
            result = i;
            break;
        }
    }
    if (result == -1) {
        throw std::runtime_error("Division by zero or no multiplicative inverse exists.");
    }
    return GF_ELEMENT((this->value * result) % gf);
}

// << 
std::ostream& operator<<(std::ostream& os, const GF_ELEMENT& elem) {
    os << elem.value;
    return os;
}
