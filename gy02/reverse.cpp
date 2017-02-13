/*
 * reverse.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(const char* source, char* target) {
    int i, n=strlen(source);
    for(i=0; i<n; i++) {
        target[i] = source[n-i-1];
    }
    target[n] = '\0';
}

int main(int argc, char* argv[]) {
    char* target = (char*)malloc(sizeof(char) * (strlen(argv[1])+1));
    reverse(argv[1], target);
    printf("%s\n", target);
    free(target);
    return 0;
}

