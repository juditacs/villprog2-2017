/*
 * argv_examples.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 *
 * Print first N perfect numbers.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isPerfect(int n) {
    double s = sqrt(n);
    int i, sum = 0;
    for (i=1; i<s; i++) {
        if (n % i == 0) {
            int pair = n / i;
            if (pair != i && pair < n) sum += pair;
            sum += i;
        }
    }
    return sum == n;
}

int main(int argc, char* argv[]) {
    int found=0, n=1, until;
    // print first argv[1] numbers if argv[1] is specified
    // otherwise print first 3 perfect numbers
    until = (argc < 2) ? 3 : atoi(argv[1]);
    while (found < until) {
        if (isPerfect(n)) {
            found++;
            printf("%d\n", n);
        }
        n++;
    }
    return 0;
}

