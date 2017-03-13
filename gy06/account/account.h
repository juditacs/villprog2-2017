/*
 * account.h
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
    static const double HUF_USD;
    const long accountNumber;
    double balance;
public:
    Account(long accountNumber, double balance=0):
        accountNumber(accountNumber), balance(balance) {}
    long getAccountNumber() const;
    double getBalance() const;
    void setBalance(double);
    double getUSDBalance() const ;
    static double getUSDExchange();
};

#endif /* !ACCOUNT_H */
