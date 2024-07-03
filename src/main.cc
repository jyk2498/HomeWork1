#include "GF_field.hh"


int main(void) {
    srand(time(NULL));

    // example code
    int random_exp = (rand() % GF_FIELD.get_size());
    GF_ELEMENT a(random_exp); // ��ü a����
    random_exp = (rand() % GF_FIELD.get_size());
    GF_ELEMENT b(random_exp); // ��ü b����

    std::cout << a + b << std::endl;
    std::cout << a * b << std::endl;
    std::cout << a - b << std::endl;
    std::cout << a / b << std::endl;
    //std::cout << a % b << std::endl;

    return 0;
}
