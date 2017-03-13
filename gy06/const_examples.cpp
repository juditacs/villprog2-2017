/*
 * const_examples.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

class A {
    const int a;
    int b;
public:
    A(int a, int b=0): a(a) { this->b = b; }
    int getA() const { return a; }
    int getB() const { return b; }
    void setB(const int& newB) { b = newB;}
};

int main() {
    A a1(1, 2);
    std::cout << a1.getA() << " " << a1.getB() << std::endl;
    const A a2(3, 4);
    std::cout << a2.getA() << " " << a2.getB() << std::endl;
    a1.setB(12);
    return 0;
}
