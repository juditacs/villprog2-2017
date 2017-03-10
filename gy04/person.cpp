/*
 * person.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "person.h"

Person::Person(const char* firstName, const char* lastName) {
    setFirstName(firstName);
    setLastName(lastName);
}

Person::Person(const char* firstName, const char* lastName, const char* taxId) {
    setFirstName(firstName);
    setLastName(lastName);
    setTaxId(taxId);
}
void Person::setFirstName(const char* firstName) {
    if (strlen(firstName) < sizeof(this->firstName))
        strcpy(this->firstName, firstName);
}
void Person::setLastName(const char* lastName) {
    if (strlen(lastName) < sizeof(this->lastName))
        strcpy(this->lastName, lastName);
}
void Person::setTaxId(const char* taxId) {
    strcpy(this->taxId, taxId);
    return;
    if (strlen(taxId) < sizeof(this->taxId))
        strcpy(this->taxId, taxId);
    else {
        printf("Tul hosszu a taxId\n");
    }
}
