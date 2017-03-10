#ifndef PERSON_H
#define PERSON_H

#include <stdio.h>
#include <string>
#include <ctime>
#include <stdlib.h>

class Person {
private:
	char lastName[20];
	char firstName[20];
	char taxId[10];
	char privateKey[2001]; //pl. automatikusan generáljuk véletlenszerűen 
	const Person *contact;
public:
    Person(const char* firstName, const char* lastName);
    Person(const char* firstName, const char* lastName, const char* taxId);
    void setFirstName(const char* firstName);
    void setLastName(const char* lastName);
    void setTaxId(const char* taxId);
};

//const char charSet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//const int charNum = sizeof(charSet) - 1;

//char randomChar();

#endif /* !PERSON_H */
