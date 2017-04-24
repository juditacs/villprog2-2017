/*
 * dictionary.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <string>
#include <cstdlib>

template <class K, class V>
class Pair {
    K key;
    V value;
public:
    Pair() { key = K(); value = V();}
    Pair(K key, V value=V()): key(key), value(value) {}
    K getKey() const { return key; }
    V getValue() const { return value; }
    V& getValue() { return value; }
};

template <class K, class V>
std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
    return os << "key: " << pair.getKey() << "\tvalue: " << pair.getValue();
}

template <class K, class V>
class Dictionary {
    Pair<K, V>* pairs;
    unsigned elementNum;
    int getIndexByKey(const K& key) const {
        for(unsigned i=0; i<elementNum; i++)
            if(key == pairs[i].getKey()) return i;
        return -1;
    }
    void insertPair(const K& key, V value=V()) {
        Pair<K, V>* tmp = new Pair<K, V>[elementNum+1];
        for (unsigned i=0; i<elementNum; i++) tmp[i] = pairs[i];
        tmp[elementNum] = Pair<K, V>(key, value);
        elementNum++;
        delete[] pairs;
        pairs = tmp;
    }
public:
    Dictionary(): pairs(NULL), elementNum(0) {}
    ~Dictionary() { delete[] pairs; }
    Dictionary(const Dictionary& other) {
        pairs = NULL;
        *this = other;
    }
    Dictionary& operator=(const Dictionary<K, V>& rhs) {
        if (*this == rhs) {
            return *this;
        }
        delete[] pairs;
        elementNum = rhs.elementNum;
        pairs = new Pair<K, V>[elementNum];
        for (unsigned i=0; i<elementNum; i++) pairs[i] = rhs.pairs[i];
        return *this;
    }
    bool operator==(const Dictionary<K, V>& rhs) const {
        if (elementNum != rhs.elementNum) return false;
        for(unsigned i=0; i<elementNum; i++) {
            K key = pairs[i].getKey();
            V value = pairs[i].getValue();
            if (!rhs.isElement(key) || rhs[key] != value) return false;
        }
        return true;
    }
    bool isElement(const K& key) const { return getIndexByKey(key) != -1; }
    const V& operator[](const K& key) const {
        int idx = getIndexByKey(key);
        if (idx == -1) return pairs[elementNum-1].getValue();
        return pairs[idx].getValue();
    }
    V& operator[](const K& key) {
        int idx = getIndexByKey(key);
        if (idx != -1) return pairs[idx].getValue();
        insertPair(key);
        return pairs[elementNum-1].getValue();
    }
    unsigned size() const { return elementNum; }
    void print(std::ostream& os) const {
        for(unsigned i=0; i<elementNum; i++) {
            os << pairs[i] << std::endl;
        }
    }
    void deleteKey(const K& key) {
        int idx = getIndexByKey(key);
        if (idx == -1) return;
        Pair<K, V>* tmp = new Pair<K, V>[elementNum-1];
        int j = 0;
        for(unsigned i=0; i<elementNum; i++) {
            if ((unsigned)idx != i) {
                tmp[j] = pairs[j];
                j++;
            }
        }
        elementNum--;
        delete[] pairs;
        pairs = tmp;
    }
};

template <class K, class V>
std::ostream& operator<<(std::ostream& os, const Dictionary<K, V>& d) {
    d.print(os);
    return os;
}

class Computer {
    std::string type;
    unsigned cpu, ram;
public:
    Computer(std::string type="unknown", unsigned cpu=3, unsigned ram=32):
        type(type), cpu(cpu), ram(ram) {}
    unsigned getCpu() const { return cpu; }
    unsigned getRam() const { return ram; }
    std::string getType() const { return type; }
    bool operator==(const Computer& rhs) const {
        return type == rhs.type && ram == rhs.ram && cpu == rhs.cpu;
    }
    /*
    bool operator!=(const Computer& rhs) const { return !(*this == rhs);}
    */
};
std::ostream& operator<<(std::ostream& os, const Computer& c) {
    return os << "type: " << c.getType() << ", CPU: " << c.getCpu() << ", RAM: " << c.getRam();
}
int main() {
    Dictionary<Computer, int> d;
    d[Computer("HP Folio 9470m", 4, 12)] = 12;
    d[Computer("HP Elitebook 2540p", 4, 8)] = 1;
    d[Computer("HP Elitebook 2530p", 4, 4)] = 3;
    std::cout << d;
    return 0;
}

int main2(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Need at least two parameters" << std::endl;
        return -1;
    }
    Dictionary<std::string, int> d;
    for(int i=1; i<argc; i++) {
        std::string key = argv[i];
        d[key] += 1;
        //std::cout << "Size of dictionary: " << d.size() << std::endl;
        d.deleteKey("fekete");
    }
    Dictionary<std::string, int> d2(d);
    std::cout << d2;
    return 0;
}
