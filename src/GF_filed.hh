#ifndef GF_FIELD_HH
#define GF_FIELD_HH

#include <iostream>

class GF_FIELD { // gf 정의
    public:
        static const int field_size = 256;  // 내 맘대로 설정?
        static int get_size() {
            return field_size;
        }
    //private:
};

class GF_ELEMENT { // gf 원소 표현
    public:
        // 생성자
        GF_ELEMENT(int val) : value(val% GF_FIELD::get_size()) {}

        // 연산자 오버로딩
        GF_ELEMENT operator+(const GF_ELEMENT& other) const;
        GF_ELEMENT operator-(const GF_ELEMENT& other) const;
        GF_ELEMENT operator*(const GF_ELEMENT& other) const;
        GF_ELEMENT operator/(const GF_ELEMENT& other) const;

        // 출력 연산자 오버로딩
        friend std::ostream& operator<<(std::ostream& os, const GF_ELEMENT& elem);  
    private:
        int value;
};

#endif 
