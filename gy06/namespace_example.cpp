/*
 * namespace_example.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

namespace modulo10 {
    const unsigned int MY_TEST_CONST = 999;

    int mod(int divident) {
        return divident & 10;
    }
}
namespace modulo20 {
    int mod(int divident) {
        return divident & 20;
    }
    namespace modulo25 {
        const unsigned int MY_TEST_CONST = 333;
        int mod(int divident) {
            return divident % 25;
        }
    }
}
int cout() {
    return 0x7fffffff;
}
using namespace std;

int main() {
    using namespace modulo10;
    using std::cout;
    cout << MY_TEST_CONST << " mod 10 = " << mod(1234) << endl;
    cout << modulo20::modulo25::MY_TEST_CONST << " mod 20 = " << modulo20::mod(1234) << endl;
    cout << MY_TEST_CONST << " mod 25 = " << modulo20::modulo25::mod(1234) << endl;
    cout << ::cout() << endl; 
    return 0;
}
