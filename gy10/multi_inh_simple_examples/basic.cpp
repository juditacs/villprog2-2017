#include <iostream>

class A {
protected:
    int i;
public:
    A() {std::cout<<"ACD ";}
    A(int i): i(i) {std::cout<<"ACI"<<i<<" ";}
    ~A() {std::cout<<"AD ";}
};

class B {
protected:
    int i;
public:
    B() {std::cout<<"BCD ";}
    B(int i): i(i) {std::cout<<"BCI"<<i<<" ";}
    ~B() {std::cout<<"BD ";}
};

class C: public A, public B {
public:
    C() {std::cout<<"CCD ";}
    C(int i, int j): A(i), B(j) {std::cout<<"CCI ";}
    ~C() {std::cout<<"CD ";}
    void print() {std::cout<<A::i<<" "<<B::i;}
};

int main() {
    C c(1, 2);
    c.print();
    return 0;
}
