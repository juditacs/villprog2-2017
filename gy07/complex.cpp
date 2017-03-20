/*
 * complex.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <cstdlib>
#include <math.h>

class Complex {
public:
    double re, im;
    Complex(double re, double im): re(re), im(im) {}
    Complex(const Complex& other) { 
        //std::cout << "copy ctor" << std::endl;
        *this = other;
    }
    bool operator==(const Complex& rhs) const {
        return re == rhs.re && im == rhs.im;
    }
    const Complex& operator=(const Complex& rhs) {
    //const Complex& operator=(Complex rhs) {
        //std::cout << "op=" << std::endl;
        re = rhs.re;
        im = rhs.im;
        return *this;
    }
    const Complex& operator=(double d) {
        re = d;
        im = 0;
        return *this;
    }
};
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.re << "+j" << c.im;
    return os;
}
int main() {
    Complex c1(3, 4), c2(1, 1);
    const Complex c3(1, 1);
    Complex c4(0, 0);
    c1 = (c4 = c2);
    //std::cout << (c4 == c1) << std::endl;
    c2 = 12.1;
    std::cout << c2 << c1 << std::endl;
    operator<<(operator<<(std::cout, c2), c1) << std::endl;
    //std::cin >> c1;
    //is.ignore(2)
}
