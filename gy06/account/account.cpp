/*
 * account.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include "account.h"

const double Account::HUF_USD = 286.03;

long Account::getAccountNumber() const {
    return accountNumber;
}
double Account::getBalance() const {
    return balance;
}
void Account::setBalance(double newBalance) {
    balance = newBalance;
}
double Account::getUSDBalance() const {
    return balance / Account::HUF_USD;
}
double Account::getUSDExchange() {
    return Account::HUF_USD;
}
