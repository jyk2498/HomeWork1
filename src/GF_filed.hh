#ifndef GF_FIELD_HH
#define GF_FIELD_HH

#include <iostream>

class GF_FIELD { // gf ����
    public:
        static const int field_size = 256;  // �� ����� ����?
        static int get_size() {
            return field_size;
        }
    //private:
};

class GF_ELEMENT { // gf ���� ǥ��
    public:
        // ������
        GF_ELEMENT(int val) : value(val% GF_FIELD::get_size()) {}

        // ������ �����ε�
        GF_ELEMENT operator+(const GF_ELEMENT& other) const;
        GF_ELEMENT operator-(const GF_ELEMENT& other) const;
        GF_ELEMENT operator*(const GF_ELEMENT& other) const;
        GF_ELEMENT operator/(const GF_ELEMENT& other) const;

        // ��� ������ �����ε�
        friend std::ostream& operator<<(std::ostream& os, const GF_ELEMENT& elem);  
    private:
        int value;
};

#endif 
