/*
 * file.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <string.h>
#include <stdio.h>
#include "file.h"

File::File() {
    name = new char[1];
    name[0] = '\0';
    extension = new char[1];
    extension[0] = '\0';
    nameLength = 0;
    extensionLength = 0;
    size = 0;
}
File::File(const File& other) {
    name = new char[other.nameLength+1];
    strcpy(name, other.name);
    nameLength = other.nameLength;
    extension = new char[other.extensionLength+1];
    strcpy(extension, other.extension);
    extensionLength = other.extensionLength;
    size = other.size;
}

File::~File() {
    delete[] name;
    delete[] extension;
}
void File::setName(const char* name) {
    delete[] this->name;
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    nameLength = strlen(name);
}
void File::setExtension(const char* extension) {
    delete[] this->extension;
    this->extension = new char[strlen(extension)+1];
    strcpy(this->extension, extension);
    extensionLength = strlen(extension);
}

void File::print() {
    printf("%s.%s\t%u\n", name, extension, size);
}

void File::copy(const File& other) {
	setName(other.name);
	setExtension(other.extension);
    size = other.size;
	//setSize(other.getSize());
}
