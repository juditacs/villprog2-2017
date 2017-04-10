#include <iostream>

class A {
public:
    int i;
    A(int i): i(i) {}
    virtual ~A() {}
};

class B {
public:
    int i;
    B(int i): i(i) {}
};

class C: public A, public B {
public:
    C(int i, int j): A(i), B(j) {}
};

int main() {
    C* p = new C(1, 2);
    std::cout << ((B*)p)->i << std::endl;
    std::cout << ((A*)p)->i << std::endl;
    // keresztbe castolasi!
    A* pa = new C(1, 5);
    std::cout << ((B*)pa)->i << std::endl;
    A* pb = new C(3, 4);
    std::cout << pb->i << std::endl;
    delete p;
    delete pa;
    delete pb;
    return 0;
}
