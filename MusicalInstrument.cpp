#include "MusicalInstrument.h"
#include <iostream>
using namespace std;

MusicalInstrument::MusicalInstrument(const string& name, int StringsCount)
    : name(name), stringsCount(StringsCount) {}

MusicalInstrument::~MusicalInstrument() {}

void MusicalInstrument::play() {
    cout << name << " играет!" << endl;
}

void MusicalInstrument::tune() {
    cout << name << " настраивается." << endl;
}

void MusicalInstrument::describe() {
    cout << "Это " << name << " с " << stringsCount << " струнами/клавишами." << endl;
}

void MusicalInstrument::specialFeature() {
    cout << "У этого инструмента уникальное звучание." << endl;
}

void MusicalInstrument::setName(const string& newName) { name = newName; }
string MusicalInstrument::getName() { return name; }
void MusicalInstrument::setStringsCount(int count) { stringsCount = count; }
int MusicalInstrument::getStringsCount() { return stringsCount; }
