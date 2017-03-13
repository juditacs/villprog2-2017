/*
 * main.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include "account.h"

int main() {
    Account a1(1, 10);
    std::cout << a1.getBalance() << std::endl;
    a1.setBalance(20010);
    std::cout << a1.getBalance() << std::endl;
    const Account a2(10, 20);
    std::cout << a2.getBalance() << std::endl;
    std::cout << "a1: " << a1.getUSDBalance() << std::endl;
    std::cout << "a2: " << a2.getUSDBalance() << std::endl;
    return 0;
}

