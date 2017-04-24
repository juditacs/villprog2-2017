/*
 * template_example.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

class Complex {
public:
    double re, im;
    Complex(double re=0, double im=0): re(re), im(im) {}
    bool operator>(const Complex& rhs) const {
        return re*re + im*im > rhs.re*rhs.re + rhs.im*rhs.im;
    }
};
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    return os<<c.re<<"+j"<<c.im;
}

template <class T>
T max(const T& a, const T& b) {
    return a > b ? a : b;
}

template <class T, class S>
bool same_class(const T&, const S&) {
    return false;
}
template <class T>
bool same_class(const T&, const T&) {
    return true;
}

class A {};
class B: public A {};

int main() {
    std::cout << max(2, 3) << std::endl;
    std::cout << max<double>(2, 3.2) << std::endl;
    std::cout << max(Complex(2, 1), Complex(1, 1)) << std::endl;
    std::cout << std::boolalpha << same_class(2, 3) << std::endl;
    std::cout << std::boolalpha << same_class(2, 3.1) << std::endl;
    return 0;
}
