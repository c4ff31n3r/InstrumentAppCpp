#include "Guitar.h"
#include <iostream>
using namespace std;

Guitar::Guitar(const string& name, int stringsCount, const string& guitarType, bool hasPickup)
    : MusicalInstrument(name, stringsCount), guitarType(guitarType), hasPickup(hasPickup) {}

Guitar::Guitar(const string& name, int stringsCount, const string& guitarType, bool hasPickup, const string& color)
    : MusicalInstrument(name, stringsCount), guitarType(guitarType), hasPickup(hasPickup), color(color) {}

void Guitar::strum() {
    cout << name << " ���������� ������." << endl;
}

void Guitar::changeStrings() {
    cout << "� " << name << " �������� ������." << endl;
}

void Guitar::describe() {
    cout << "��� " << guitarType << " ������ " << name << " � " << stringsCount << " ��������." << endl;
    if (hasPickup) {
        cout << "� �� ���� �������������� ��� ��������." << endl;
        cout << "���� ������: " << color << endl;
    }
}

void Guitar::specialFeature() {
    cout << "������ ����� ������ ��� �������, ��� � �������." << endl;
}
