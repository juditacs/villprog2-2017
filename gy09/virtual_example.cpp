/*
 * inheritance_example.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

class A {
public:
    virtual void f1() const {std::cout<<"AF1 ";}
    void f2() const {std::cout<<"AF2 ";}
    virtual ~A() {std::cout<<"AD ";}
    virtual void f3() = 0;
};
class B: public A {
public:
    void f1() const {std::cout<<"BF1 ";}
    void f2() const {std::cout<<"BF2 ";}
    void f3() {std::cout<<"BF3 ";}
    ~B() {std::cout<<"BD ";}
};
int main() {
    /*
    B b;
    b.f1();
    b.f2();
    b.f3();
    */
    A* pb = new B;
    pb->f1();
    pb->f2();
    pb->f3();
    delete pb;
    std::cout << std::endl;
    return 0;
}
