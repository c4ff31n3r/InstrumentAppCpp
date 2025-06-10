#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "MusicalInstrument.h"
#include "Guitar.h"
#include "Piano.h"
using namespace std;

void clearInput() {
    cin.clear(); // ����� ����� ������
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ������
}

int getIntInput(const string& prompt, int minVal = INT_MIN, int maxVal = INT_MAX) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (!cin.fail() && value >= minVal && value <= maxVal) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "������������ ����. ���������� �����.\n";
        clearInput();
    }
}

bool getBoolInput(const string& prompt) {
    int val = getIntInput(prompt + " (1 - ��, 0 - ���): ", 0, 1);
    return val == 1;
}

void showInstrumentActions() {
    cout << "\n--- ���� �������� ---\n";
    cout << "1. �������� �����������\n";
    cout << "2. ��������� ����������\n";
    cout << "3. ������\n";
    cout << "4. �����������\n";
    cout << "5. �������� ���\n";
    cout << "6. �������� ���������� �����\n";
    cout << "0. �����\n";
    cout << "�����: ";
}

int main() {
    setlocale(LC_ALL, "");

    vector<shared_ptr<MusicalInstrument>> instruments;
    int choice;

    do {
        cout << "\n=== ������� ���� ===\n";
        cout << "1. �������� ����������\n";
        cout << "2. ������� ����������\n";
        cout << "3. ������� ���������� ��� ��������������\n";
        cout << "0. �����\n";
        choice = getIntInput("�����: ", 0, 3);

        if (choice == 1) {
            int type = getIntInput("�������� ��� ����������� (1 - ������, 2 - �������, 3 - ������): ", 1, 3);
            cin.ignore();

            string name;
            cout << "������� �������� �����������: ";
            getline(cin, name);

            int count = getIntInput("������� ���������� �����/������: ", 1);

            if (type == 1) {
                string gtype;
                cout << "��� ������ (1 - ������������, 2 - �������������): ";
                getline(cin, gtype);


                string gcolor;
                cout << "������� ���� ������: ";
                getline(cin, gcolor);

                if (gtype == "2") {
                    instruments.push_back(make_shared<Guitar>(name, count, "�������������", true, gcolor));
                }
                else {
                    bool pickup = getBoolInput("���� �� ��������������?");
                    instruments.push_back(make_shared<Guitar>(name, count, "������������", pickup, gcolor));
                }

                
            }
            else if (type == 2) {
                int pedals = getIntInput("���������� �������: ", 0);
                bool grand = getBoolInput("��� �����?");
                instruments.push_back(make_shared<Piano>(name, count, pedals, grand));
            }
            else {
                instruments.push_back(make_shared<MusicalInstrument>(name, count));
            }

        }
        else if (choice == 2) {
            if (instruments.empty()) {
                cout << "��� ������������ ��� ��������." << endl;
                continue;
            }
            cout << "�������� ���������� �� �������:\n";
            for (size_t i = 0; i < instruments.size(); ++i)
                cout << i << ") " << instruments[i]->getName() << endl;

            int idx = getIntInput("�����: ", 0, instruments.size() - 1);
            instruments.erase(instruments.begin() + idx);
            cout << "���������� �����." << endl;

        }
        else if (choice == 3) {
            if (instruments.empty()) {
                cout << "������ ������������ ����." << endl;
                continue;
            }

            cout << "�������� ���������� �� �������:\n";
            for (size_t i = 0; i < instruments.size(); ++i)
                cout << i << ") " << instruments[i]->getName() << endl;

            int index = getIntInput("�����: ", 0, instruments.size() - 1);
            int action;

            do {
                showInstrumentActions();
                action = getIntInput("", 0, 6);
                switch (action) {
                case 1: instruments[index]->describe(); break;
                case 2: instruments[index]->tune(); break;
                case 3: instruments[index]->play(); break;
                case 4: instruments[index]->specialFeature(); break;
                case 5: {
                    string newName;
                    cout << "����� ���: ";
                    getline(cin, newName);
                    instruments[index]->setName(newName);
                    break;
                }
                case 6: {
                    int newCount = getIntInput("����� ���������� �����/������: ", 1);
                    instruments[index]->setStringsCount(newCount);
                    break;
                }
                case 0: break;
                default: cout << "�������� �����." << endl;
                }
            } while (action != 0);
        }

    } while (choice != 0);

    cout << "���������� ���������.\n";
    return 0;
}
