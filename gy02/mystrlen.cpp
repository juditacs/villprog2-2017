/*
 * mystrlen.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

int strlen(const char* str) {
    int i;
    for (i=0; str[i]; i++);
    return i;
}

int main(int argc, char* argv[]) {
    int i;
    for (i=0; i<argc; i++) {
        printf("A %d. parancssori argumentum: %s, amelynek hossza: %d\n",
                i+1, argv[i], strlen(argv[i]));
    }
    return 0;
}

