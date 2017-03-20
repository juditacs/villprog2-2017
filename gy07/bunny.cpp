/*
 * bunny.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */
#include <iostream>

class Egg {
private:
	unsigned int weight;
public:
	Egg(unsigned int param = 0) : weight(param) {}
    friend std::ostream& operator<<(std::ostream& os, const Egg& egg);
    bool operator==(const Egg& rhs) const {
        return this->weight == rhs.weight;
    }
    bool operator!=(const Egg& rhs) const {
        return !(*this == rhs);
    }
};

class EasterBunny {
private:
	unsigned elementNum;
	Egg* pData;
public:
	EasterBunny() { elementNum = 0; pData = NULL; }
    EasterBunny(const EasterBunny& other) {
        //std::cout << "copy ctor" << std::endl;
        pData = NULL;
        *this = other;
    }
    const EasterBunny& operator=(const EasterBunny& rhs) {
        if (*this == rhs) return *this;
        delete[] pData;
        if (rhs.elementNum == 0) {
            elementNum = 0;
            pData = NULL;
        }
        else {
            elementNum = rhs.elementNum;
            pData = new Egg[elementNum];
            for (unsigned int i = 0; i<elementNum; i++) pData[i] = rhs.pData[i];
        }
        return *this;
    }
    bool operator==(const EasterBunny& rhs) const {
        if (this->elementNum != rhs.elementNum) return false;
        for (unsigned int i=0; i<elementNum; i++) {
            if (pData[i] != rhs.pData[i]) return false;
        }
        return true;
    }
    EasterBunny operator+(const EasterBunny& rhs) const {
        //std::cout << "op=" << std::endl;
        EasterBunny newBunny;
        for (unsigned int i=0; i<elementNum; i++) newBunny.insert(pData[i]);
        for (unsigned int i=0; i<rhs.elementNum; i++) newBunny.insert(rhs.pData[i]);
        return newBunny;
    }
    bool insert(const Egg& element) {
        if (isElement(element)) return true;
        Egg* temp = new Egg[elementNum+1];
        if (temp != NULL) {
            for (unsigned int i=0; i<elementNum; i++) temp[i] = pData[i];
            temp[elementNum] = element;
            elementNum++;
            delete[] pData;
            pData = temp;
            return true;
        }
        return false;
    }
    bool isElement(const Egg& element) const {
        for (unsigned int i=0; i<elementNum; i++) {
            if (pData[i] == element) return true;
        }
        return false;
    }
    ~EasterBunny() { delete[] pData; }
    friend std::ostream& operator<<(std::ostream& os, const EasterBunny& bunny);
};
std::ostream& operator<<(std::ostream& os, const Egg& egg) {
    os << egg.weight;
    return os;
}
std::ostream& operator<<(std::ostream& os, const EasterBunny& bunny) {
    for (unsigned int i=0; i<bunny.elementNum; i++) {
        os << bunny.pData[i];
        if (i < bunny.elementNum-1) os << " ";
    }
    return os;
}

int main() {
	Egg redEgg(9);
	Egg glitterEgg(27);
	Egg greenEgg(42);
	Egg blueEgg(42);

	EasterBunny bunny1;
	EasterBunny bunny2;

    //std::cout << (blueEgg == greenEgg) << std::endl;
    //std::cout << (redEgg != glitterEgg) << std::endl;
	bunny1.insert(redEgg);
	bunny2.insert(glitterEgg);
	bunny2.insert(greenEgg);
    EasterBunny bunny3;
    bunny3.insert(glitterEgg);
    bunny3.insert(blueEgg);

    //std::cout << std::boolalpha << (bunny2 == bunny3) << std::endl;
    std::cout << bunny1 << std::endl;
	std::cout << bunny2 << std::endl;

	EasterBunny bunny = bunny1 + bunny2 + bunny3;

    std::cout << bunny << std::endl;

	if (bunny1 == bunny2)
		std::cout << "Twins." << std::endl;

	bunny1 = bunny2;
	if (bunny1 == bunny2)
		std::cout << "Twins." << std::endl;

	return 0;
}

