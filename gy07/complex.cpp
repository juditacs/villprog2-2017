#include <iostream>

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
    //const Complex& operator=(Complex rhs) { // vegtelen ciklus lenne
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

    // az alabbi ket sor azonos
    std::cout << c2 << c1 << std::endl;
    operator<<(operator<<(std::cout, c2), c1) << std::endl;
}
