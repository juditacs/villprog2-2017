/*
 * folder.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <string.h>
#include "folder.h"

Folder::Folder(const char* name) {
    this->nameLength = strlen(name);
    this->name = new char[this->nameLength+1];
    strcpy(this->name, name);
    files = NULL;
    elementNum = 0;
}
Folder::~Folder() {
    delete[] name;
    delete[] files;
}
void Folder::addFile(const File& file) {
	File* temp = new File[elementNum + 1];
	for (unsigned int i = 0; i < elementNum; i++)
		temp[i].copy(files[i]);
	delete[] files;
	temp[elementNum].copy(file);
	elementNum++;
	files = temp;
}
void Folder::listDir() {
    printf("%s\n", name);
    for (unsigned i=0; i<elementNum; i++) {
        files[i].print();
    }
}
