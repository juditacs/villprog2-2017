/*
 * exception_example.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <cstdlib>

class Noisy {
public:
    int n;
    Noisy(int n): n(n) {std::cout<<"Noisy " << n << " created"<<std::endl;}
    ~Noisy() {std::cout<<"Noisy " << n << " destroyed"<<std::endl;}
};

class TooManyFailures: public std::out_of_range {
public:
    TooManyFailures(std::string s): std::out_of_range(s) {}
};

int passRatio(unsigned percent) {
    Noisy* n = new Noisy(1);
    if (percent < 10) throw TooManyFailures("Too many students failed");
    if (percent > 100) throw std::out_of_range("Percent cannot be over 100");
    Noisy n2(2);
    delete n;
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "I need a parameter" << std::endl;
        return -1;
    }
    try {
        Noisy n3(3);
        passRatio(atoi(argv[1]));
    }
    catch(TooManyFailures e) {
        std::cerr << "TooManyFailures: " << e.what() << std::endl;
    }
    catch(std::out_of_range e) {
        std::cerr << "out_of_range: " << e.what() << std::endl;
    }
    catch(std::logic_error e) {
        std::cerr << "logic_error: " << e.what() << std::endl;
    }
    catch(int i) {
        std::cerr << "Caught int exception\n";
    }
    catch(...) {
        std::cerr << "Caught unknown exception\n";
    }
    return 0;
}
