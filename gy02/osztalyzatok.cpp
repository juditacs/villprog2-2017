/*
 * osztalyzatok.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

void indexedCount(int* eredmenyek, int n, int* hisztogram, int m) {
    int i;
    for (i=0; i<m; i++) hisztogram[i] = 0;
    for (i=0; i<n; i++) hisztogram[eredmenyek[i]] ++;
}
void max(int* array, int n, int& place) {
    place = n-1;
    for (n=n-2; n>=0; n-- ) {
        if (array[n] > array[place]) place = n;
    }
}
int main() {
    int zh[] = {0, 12, 50, 48, 48, 0, 1, 1, 3, 1, 5, 23, 26};
    int pontszamok[51] = {0};
    int place;
    indexedCount(zh, 13, pontszamok, 51);
    max(pontszamok, 51, place);
    printf("Leggyakoribb pontszam: %d, %dx fordul elo\n", place, pontszamok[place]);
    return 0;
}

