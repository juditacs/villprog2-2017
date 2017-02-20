/*
 * gumimaci.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Person {
    char firstName[20];
    char lastName[20];
    char taxId[11];
    char privateKey[2000];
    struct Person *contact;
    int serialNumber;
} Person;

typedef struct Company {
    char name[50];
    char taxNumber[11];
    char privateKey[2000];
    struct Company* contact;
} Company;

Company* readCompany(FILE* fp) {
    Company* c = (Company*)malloc(sizeof(Company));
    if ((fscanf(fp, "%s%s%s", c->name, c->taxNumber, c->privateKey)) != 3)
        return NULL;
    return c;
}

Company* readCompaniesFromFile(const char* companyFile) {
    FILE* cf = fopen(companyFile, "rt");
    Company *head = NULL, *tmp;
    head = readCompany(cf);
    tmp = head;
    while((tmp->contact = readCompany(cf)) != NULL) tmp = tmp->contact;
    fclose(cf);
    return head;
}

Person* readPerson(FILE* fp) {
    Person* p = (Person*)malloc(sizeof(Person));
    assert(p); // foglalas ellenorzese
    if ((fscanf(fp, "%s%s%s%s", p->firstName, p->lastName, p->taxId, p->privateKey)) != 4)
        return NULL;
    return p;
}

Person* readPersonsFromFile(const char* personFile) {
    FILE* pf = fopen(personFile, "rt");
    Person *head = NULL, *tmp;
    head = readPerson(pf);
    tmp = head;
    while((tmp->contact = readPerson(pf)) != NULL) tmp = tmp->contact;
    fclose(pf);
    return head;
}
void clean(Person* head) {
    if (head == NULL) return;
    clean(head->contact);
    free(head);
}
void clean(Company* head) {
    if (head == NULL) return;
    clean(head->contact);
    free(head);
}
void print(const Person& p) {
    printf("%s %s, %s", p.firstName, p.lastName, p.taxId);
    if (p.contact != NULL) printf(", contact: %s", p.contact->lastName);
    printf("\n");
}
void printList(const Person* persons) {
    while (persons != NULL) {
        print(*persons);
        persons = persons->contact;
    }
}
void reversePrint(const Person* person) {
    if (person == NULL) return;
    reversePrint(person->contact);
    print(*person);
}
const Person& findRoot(const Person& person) {
    if (person.contact == NULL) {
        // megallas az utolso rekurziv hivasnal, igy tudtuk megnezni a
        // memoriahasznalatot
        //scanf(" ");
        return person;
    }
    return findRoot(*(person.contact));
}
Person findRootBad(Person person) {
    if (person.contact == NULL) return person;
    return findRootBad(*(person.contact));
}
const Person* findRoot(const Person* person) {
    if (person->contact == NULL) {
        //scanf(" ");
        return person;
    }
    return findRoot(person->contact);
}
void setSerialNumber(Person* p) {
    if (p->contact == NULL) p->serialNumber = 0;
    else {
        setSerialNumber(p->contact);
        p->serialNumber = p->contact->serialNumber + 1;
    }
}
void setSerialNumber(Person& p) {
    if (p.contact == NULL) p.serialNumber = 0;
    else {
        setSerialNumber(p.contact);
        p.serialNumber = p.contact->serialNumber + 1;
    }
}
int main(int argc, char* argv[]) {
    // ellenorzes, hogy kaptunk-e elso es masodik parametert
    if (argc < 3) {
        printf("Usage: %s PERSON_FILE COMPANY_FILE\n", argv[0]);
        return -1;
    }
    // adatok beolvasasa
    Person* persons = readPersonsFromFile(argv[1]);
    Company* companies = readCompaniesFromFile(argv[2]);

    // a stack-zabalo rekurziv fuggveny. Probald ki nagyobb inputtal (ld.
    // commands.md)
    // findRootBad(*persons);
    // printf("Tuljutottam a stack gyilkoson\n");

    // kiiras tesztelese
    printf("=============== Elso ember ===============\n");
    print(*persons);

    // teljes lista kiirasa
    printf("\n=============== Teljes lista ===============\n");
    printList(persons);

    // gyokerelem kiirasa
    printf("\n=============== Gyokerelem ===============\n");
    print(*findRoot(persons));

    // beajanlasi sor felterkepezese
    printf("\n=============== Beajanlasi lista ===============\n");
    setSerialNumber(*persons); // refernciat var
    //setSerialNumber(persons); // pointert var
    printf("Utolso ember sorszama: %d\n", persons->serialNumber);
    printf("Elso ember sorszama: %d\n", findRoot(persons)->serialNumber);

    clean(persons);
    clean(companies);
    return 0;
}

