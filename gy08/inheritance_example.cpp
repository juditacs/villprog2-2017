/*
 * inheritance_example.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

class A {
protected:
    int a;
public:
    A() {std::cout << "A default constructor\n";}
    A(const A& other): a(other.a) {std::cout << "A cpy constructor\n";}
    A(int a): a(a) {std::cout << "A(int) constructor\n";}
    //~A() {std::cout << "A destructor\n";}
    void print() const {std::cout << a << std::endl;}
};

class B: public A {
    int b;
public:
    B(): A(0) {std::cout << "B default constructor\n";}
    B(const B& other): A(other.a), b(other.b) {std::cout << "B cpy constructor\n";}
    B(int a, int b): A(a), b(b) {std::cout<<"B(int, int) constructor\n";}
    //~B() {std::cout << "B destructor\n";}
    void print() const {std::cout << a << " " << b << std::endl;}
};
void print(A* a) {
    a->print();
}
void print(B b) {
    b.print();
}
int main() {
    B b(1, 2);
    print(b);
    //std::cout << "hello" << std::endl;
    return 0;
}
