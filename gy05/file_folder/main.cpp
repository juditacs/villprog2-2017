/*
 * main.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include "file.h"
#include "folder.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Need at least two arguments.\n");
        return -1;
    }
    File f1;
    f1.setName(argv[1]);
    f1.setExtension(argv[2]);
    //f1.print();

    File f2(f1); // f2{f1}
    File f3;
    //f3 = f1; // shallow copy!!
    f1.setName("korte");

    Folder fold1("mappa1");
    fold1.addFile(f1);
    fold1.addFile(f3);
    fold1.listDir();
    return 0;
}

