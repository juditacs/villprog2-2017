/*
 * file.h
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef FILE_H
#define FILE_H

class File {
    char* name;
    char* extension;
    unsigned int nameLength;
    unsigned int extensionLength;
    unsigned int size;
public:
    // konstruktorok
    File();
    File(const File&);
    ~File();
    
    // getterek, setterek
    const char* getName() { return name; }
    void setName(const char*);
    void setExtension(const char*);

    // egyeb
    void print();
    void copy(const File&);
};

#endif /* !FILE_H */
