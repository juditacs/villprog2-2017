#include <iostream>

class A {
public:
    int i;
    A() {}
    A(int i): i(i) {}
    virtual ~A() {}
};

class B: virtual public A {
public:
    B(int i): A(i) {}
};
class C: virtual public A {
public:
    C(int i): A(i) {}
};

class D: public B, public C {
public:
    D(int i, int j): A(i), B(i), C(j) {}
};

int main() {
    D d(1, 2);
    std::cout<<d.i;
    std::cout<<std::endl;
    return 0;
}
