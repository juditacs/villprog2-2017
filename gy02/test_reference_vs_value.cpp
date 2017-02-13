/*
 * test_reference_vs_value.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

struct BigStruct {
    char s[100000];
};

void take_ref(const BigStruct& b) {
    static int called_counter = 0;
    called_counter += 1;
    printf("%d\n", called_counter);
    take_ref(b);
}

void take_val(BigStruct b) {
    static int called_counter = 0;
    called_counter += 1;
    printf("%d\n", called_counter);
    take_val(b);
}

int main(int argc, char* argv[]) {
    BigStruct b;
    if (argv[1][0] == 'R') {
        take_ref(b);
    }
    else if (argv[1][0] == 'V') {
        take_val(b);
    }
    return 0;
}

