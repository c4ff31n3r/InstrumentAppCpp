#include "Piano.h"
#include <iostream>
using namespace std;

Piano::Piano(const string& name, int stringsCount, int pedalCount, bool isGrand)
    : MusicalInstrument(name, stringsCount), pedalCount(pedalCount), isGrand(isGrand) {}

void Piano::pressPedal() {
    cout << "Нажата педаль у " << name << "." << endl;
}

void Piano::cleanKeys() {
    cout << "Клавиши " << name << " очищаются." << endl;
}

void Piano::describe() {
    cout << "Это " << (isGrand ? "рояль " : "пианино ") << name << " с " << stringsCount << " клавишами и " << pedalCount << " педалями." << endl;
}

void Piano::specialFeature() {
    cout << "Пианино может играть и мелодию, и аккомпанемент одновременно." << endl;
}
