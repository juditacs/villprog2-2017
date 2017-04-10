#include <iostream>

class IPrintable {
public:
    virtual void print() const = 0;
    virtual ~IPrintable() {}
};
void printPrintables(IPrintable** printables, int num) {
    for(int i=0; i<num; i++) printables[i]->print();
}
class ZH: public IPrintable {
public:
    void print() const {std::cout<<"ZH\n";}
};
class Note: public IPrintable {
public:
    void print() const {std::cout<<"Jegyzet\n";}
};

int main() {
    IPrintable* p[2];
    p[0] = new ZH();
    p[1] = new Note();
    printPrintables(p, 2);
    delete p[0];
    delete p[1];
    return 0;
}
