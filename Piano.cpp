#include "Piano.h"
#include <iostream>
using namespace std;

Piano::Piano(const string& name, int stringsCount, int pedalCount, bool isGrand)
    : MusicalInstrument(name, stringsCount), pedalCount(pedalCount), isGrand(isGrand) {}

void Piano::pressPedal() {
    cout << "������ ������ � " << name << "." << endl;
}

void Piano::cleanKeys() {
    cout << "������� " << name << " ���������." << endl;
}

void Piano::describe() {
    cout << "��� " << (isGrand ? "����� " : "������� ") << name << " � " << stringsCount << " ��������� � " << pedalCount << " ��������." << endl;
}

void Piano::specialFeature() {
    cout << "������� ����� ������ � �������, � ������������� ������������." << endl;
}
