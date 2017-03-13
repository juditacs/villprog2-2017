/*
 * initializer_list.cpp
 * Copyright (C) 2017 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>

class CarEngine {
    bool isDiesel;
public:
    CarEngine(bool isDiesel): isDiesel(isDiesel) {}
    void setDiesel(bool isDiesel) { this->isDiesel = isDiesel; }
};
class Car {
    CarEngine engine;
public:
    Car(bool isDiesel): engine(isDiesel) {}
};

int main() {
    //CarEngine c1(bool);
    Car car1(false);
    //CarEngine c2(c1), c3 = c1;
    return 0;
}
