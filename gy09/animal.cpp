/*
 * animal.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <string>

class Animal {
protected:
    static unsigned feedPlusEnergy;
    std::string name;
    unsigned energyPercent;
    unsigned happinessPercent;
    void setEnergy(unsigned e) {
        energyPercent = e;
        energyPercent = energyPercent > 100 ? 100 : energyPercent;
    }
    void setHappiness(unsigned h) {
        happinessPercent = h > 100 ? 100 : h;
    }
public:
    static void setFeedPlusEnergy(unsigned f) {feedPlusEnergy = f;}
    static unsigned getFeedPlusEnergy() {return feedPlusEnergy;}
    Animal(std::string name="", unsigned energyPercent=100, unsigned happinessPercent=50):
        name(name), energyPercent(energyPercent), happinessPercent(happinessPercent) {}
    virtual void print() const {std::cout<< name << "\nenergy: " << energyPercent
        << "\nhappiness: " << happinessPercent << std::endl;}
    void rest() {
        setEnergy(100);
        setHappiness(happinessPercent * 1.5);
    }
    virtual void eat() = 0;
    virtual void workout() = 0;
};

class Dog: public Animal {
protected:
    unsigned hiddenToys;
public:
    Dog(std::string name="", unsigned energyPercent=100, unsigned happinessPercent=80, unsigned toys=0):
        Animal(name, energyPercent, happinessPercent), hiddenToys(toys) {}
    void print() const {
        Animal::print();
        std::cout<< "toys: " << hiddenToys << std::endl;
    }
    void eat() {
        setEnergy(energyPercent + getFeedPlusEnergy());
        setHappiness(happinessPercent * 1.34);
    }
    void workout() {
        hiddenToys++;
        setEnergy(energyPercent * .9);
        setHappiness(happinessPercent * 1.1);
    }
};
class Horse: public Animal {
protected:
    unsigned trainingPercent;
public:
    Horse(std::string name="", unsigned energyPercent=100, unsigned happinessPercent=80, unsigned trainingPercent=0):
        Animal(name, energyPercent, happinessPercent), trainingPercent(trainingPercent) {}
    void print() const {
        Animal::print();
        if (trainingPercent > 50)
            std::cout<< name << " is a trained horse (" << trainingPercent << ")" << std::endl;
        else
            std::cout<< name << " is not very trained (" << trainingPercent << ")" << std::endl;
    }
    void eat() {
        setEnergy(energyPercent + getFeedPlusEnergy());
    }
    void workout() {
        // nincs setTrainingPercent
        trainingPercent += 1;
        setEnergy(energyPercent * .6);
        setHappiness(happinessPercent * 1.05);
    }
};
unsigned Animal::feedPlusEnergy = 0;

int main() {
    Animal* animals[2];
    animals[0] = new Dog("Buksi", 30, 50, 1);
    animals[1] = new Horse("Dragam", 42, 50, 25);
    for (int i=0; i<2; i++) {
        std::cout << "BEFORE Animal" << i+1 << std::endl;
        animals[i]->print();
        std::cout << "AFTER Animal" << i+1 << std::endl;
        animals[i]->workout();
        animals[i]->print();
        std::cout << std::endl;
    }
/*
    Dog d("Buksi", 12);
    Horse h("Kincsem", 95);
    Animal* p = &d;
    p->print();
*/
    return 0;
}
