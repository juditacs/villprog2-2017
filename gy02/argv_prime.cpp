/*
 * argv_prime.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isPrime(int n) {
    double s = sqrt(n);
    int i;
    if (n <= 1) return 0;
    if (n == 2) return 1;
    for (i=2; i<s+1; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(int argc, char* argv[]) {
    int i;
    for (i=1; i<argc; i++) {
        int n = atoi(argv[i]);
        if (isPrime(n)) printf("%d prim\n", n);
        else printf("%d nem prim\n", n);
    }
    return 0;
}

