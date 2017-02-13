/*
 * insertion_sort2.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}
void insertion_sort(int t[], int len) {
    int i, j;
    for (i=0; i<len-1; i++) {
        int min = i;
        for (j=i+1; j<len; j++) {
            if (t[min] > t[j]) min = j;
        }
        if (min != i) swap(t[min], t[i]);
    }
}
int main(int argc, char* argv[]) {
    int* array = (int*)malloc((argc-1)*sizeof(int));
    int i;
    for (i=1; i<argc; i++) {
        array[i-1] = atoi(argv[i]);
    }

    insertion_sort(array, argc-1);

    for (i=0; i<argc-1; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);
    return 0;
}

