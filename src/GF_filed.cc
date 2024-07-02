#include "GF_filed.hh"
#include <iostream>

int main() {
    GF_FIELD::initialize_tables(); // 필드 초기화

    GF_ELEMENT a(0x57); // 예제 값
    GF_ELEMENT b(0x83); // 예제 값

    // 덧셈
    GF_ELEMENT sum = a + b;
    std::cout << "Addition: " << static_cast<int>(sum.value) << std::endl;

    // 뺄셈
    GF_ELEMENT difference = a - b;
    std::cout << "Subtraction: " << static_cast<int>(difference.value) << std::endl;

    // 곱셈
    GF_ELEMENT product = a * b;
    std::cout << "Multiplication: " << static_cast<int>(product.value) << std::endl;

    // 나눗셈
    GF_ELEMENT quotient = a / b;
    std::cout << "Division: " << static_cast<int>(quotient.value) << std::endl;

    return 0;
}