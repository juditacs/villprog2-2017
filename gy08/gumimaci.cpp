/*
 * gumimaci.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */
#include <iostream>
#include <string>

class Partner {
protected:
    std::string privateKey;
    Partner* contact;
public:
    Partner(std::string key, Partner* contact): privateKey(key), contact(contact) {}
    friend std::ostream& operator<<(std::ostream& os, const Partner& p);
};
class Person: public Partner {
    std::string firstName;
    std::string lastName;
    std::string taxId;
public:
    Person(std::string first, std::string last, std::string tax, std::string key,
            Partner* contact):
        Partner(key, contact), firstName(first), lastName(last), taxId(tax) {}
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};
class Company: public Partner {
    std::string name;
    std::string taxNumber;
public:
    Company(std::string name, std::string tax, std::string key,
            Partner* contact):
        Partner(key, contact), name(name), taxNumber(tax) {}
    friend std::ostream& operator<<(std::ostream& os, const Company& c);
};
std::ostream& operator<<(std::ostream& os, const Partner& p) {
    return os << p.privateKey;
}
std::ostream& operator<<(std::ostream& os, const Person& p) {
    if (p.contact)
        os << p.firstName << " " << p.lastName << "\ncontact: " << *(p.contact);
    else
        os << p.firstName << " " << p.lastName << "\nROOT element";
    return os;
}
std::ostream& operator<<(std::ostream& os, const Company& c) {
    if (c.contact)
        os << c.name << "\ncontact: " << *(c.contact);
    else
        os << c.name << "\nROOT element";
    return os;
}
int main() {
    Person pista("Pista", "Kiss", "1234", "0000", NULL);
    Company c("ABCD", "124", "1111", &pista);
    std::cout << c << std::endl;
    return 0;
}
