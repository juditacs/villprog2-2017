/*
 * folder.h
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef FOLDER_H
#define FOLDER_H

#include "file.h"

class Folder {
    char* name;
    unsigned int nameLength;
    File* files;
    unsigned int elementNum;
public:
    Folder(const char*);
    ~Folder();
    void addFile(const File&);
    void listDir();
};

#endif /* !FOLDER_H */
