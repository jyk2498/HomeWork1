#include "GF_filed.hh"

int main() {
    GF_ELEMENT a(0x57); // Example element
    GF_ELEMENT b(0x83); // Example element

    GF_ELEMENT c = a + b;
    GF_ELEMENT d = a * b;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a + b: " << c << std::endl;
    std::cout << "a * b: " << d << std::endl;

    return 0;

    //�־��� gf�� �����׽İ��� �����۾� ��, ���� ���� ����
}
