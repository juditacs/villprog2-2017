/*
 * complex.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

class Complex {
public:
    double re, im;
    Complex(double re, double im=0): re(re), im(im) {
        std::cout << "Complex conv cons: " << re <<std::endl;
    }
    Complex& operator=(const Complex& c){
        std::cout << "Complex op=" <<std::endl;
        re=c.re;im=c.im;
        return *this;
    }
    operator const double() const {return re;}

};
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    return os << c.re << "+j" << c.im;
}
int main() {
    Complex c1(12.1);
    c1 = 3.4;
    std::cout << c1 << std::endl;
    double d1 = c1 + 2.3;
    std::cout << d1 << std::endl;
    return 0;
}
