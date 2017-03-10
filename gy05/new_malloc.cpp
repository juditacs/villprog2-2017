/*
 * new_malloc.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>


class A {
public:
    A(int a=0) { printf("A ctor called\n"); }
    ~A() { printf("A dtor called\n"); }
};

int main() {
    printf("Malloc:\n");
    A* pa = (A*)malloc(sizeof(A));
    free(pa);

    printf("=======\nNew:\n");
    A* pb = new A(12);
    delete pb;

    printf("=======\nNew[]:\n");
    A* pc = new A[3];
    delete[] pc;

    return 0;
}

