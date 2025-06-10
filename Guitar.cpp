#include "Guitar.h"
#include <iostream>
using namespace std;

Guitar::Guitar(const string& name, int stringsCount, const string& guitarType, bool hasPickup)
    : MusicalInstrument(name, stringsCount), guitarType(guitarType), hasPickup(hasPickup) {}

Guitar::Guitar(const string& name, int stringsCount, const string& guitarType, bool hasPickup, const string& color)
    : MusicalInstrument(name, stringsCount), guitarType(guitarType), hasPickup(hasPickup), color(color) {}

void Guitar::strum() {
    cout << name << " перебирает струны." << endl;
}

void Guitar::changeStrings() {
    cout << "У " << name << " меняются струны." << endl;
}

void Guitar::describe() {
    cout << "Это " << guitarType << " гитара " << name << " с " << stringsCount << " струнами." << endl;
    if (hasPickup) {
        cout << "У неё есть звукосниматель для усиления." << endl;
        cout << "Цвет гитары: " << color << endl;
    }
}

void Guitar::specialFeature() {
    cout << "Гитара может играть как аккорды, так и мелодии." << endl;
}
