/*
 * dyn.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

class A {
public:
    virtual ~A() {}
};
class B: public A {
};

int main() {
    A* pa = new A;
    A* pb = new B;
    B* b1 = dynamic_cast<B*>(pa);
    B* b2 = dynamic_cast<B*>(pb);
    std::cout << b1 << " " << b2 << std::endl;
    delete pa;
    delete pb;
    return 0;
}
