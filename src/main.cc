#include "GF_field.hh"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void) {
    // srand(time(NULL));

    // 임의의 갈루아 필드 GF(2^8) 내의 값 두 개 사용
    GF_ELEMENT a(0x57); 
    GF_ELEMENT b(0x83); 

    // 사칙연산 예시 수행
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a / b = " << (a / b) << std::endl;
    return 0;
}