#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "MusicalInstrument.h"
#include "Guitar.h"
#include "Piano.h"
using namespace std;

void clearInput() {
    cin.clear(); // Сброс флага ошибки
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
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
        cout << "Некорректный ввод. Попробуйте снова.\n";
        clearInput();
    }
}

bool getBoolInput(const string& prompt) {
    int val = getIntInput(prompt + " (1 - да, 0 - нет): ", 0, 1);
    return val == 1;
}

void showInstrumentActions() {
    cout << "\n--- Меню действий ---\n";
    cout << "1. Описание инструмента\n";
    cout << "2. Настроить инструмент\n";
    cout << "3. Играть\n";
    cout << "4. Особенность\n";
    cout << "5. Изменить имя\n";
    cout << "6. Изменить количество струн\n";
    cout << "0. Назад\n";
    cout << "Выбор: ";
}

int main() {
    setlocale(LC_ALL, "");

    vector<shared_ptr<MusicalInstrument>> instruments;
    int choice;

    do {
        cout << "\n=== Главное меню ===\n";
        cout << "1. Добавить инструмент\n";
        cout << "2. Удалить инструмент\n";
        cout << "3. Выбрать инструмент для взаимодействия\n";
        cout << "0. Выход\n";
        choice = getIntInput("Выбор: ", 0, 3);

        if (choice == 1) {
            int type = getIntInput("Выберите тип инструмента (1 - гитара, 2 - пианино, 3 - другой): ", 1, 3);
            cin.ignore();

            string name;
            cout << "Введите название инструмента: ";
            getline(cin, name);

            int count = getIntInput("Введите количество струн/клавиш: ", 1);

            if (type == 1) {
                string gtype;
                cout << "Тип гитары (1 - акустическая, 2 - электрическая): ";
                getline(cin, gtype);


                string gcolor;
                cout << "Введите цвет гитары: ";
                getline(cin, gcolor);

                if (gtype == "2") {
                    instruments.push_back(make_shared<Guitar>(name, count, "электрическая", true, gcolor));
                }
                else {
                    bool pickup = getBoolInput("Есть ли звукосниматель?");
                    instruments.push_back(make_shared<Guitar>(name, count, "акустическая", pickup, gcolor));
                }

                
            }
            else if (type == 2) {
                int pedals = getIntInput("Количество педалей: ", 0);
                bool grand = getBoolInput("Это рояль?");
                instruments.push_back(make_shared<Piano>(name, count, pedals, grand));
            }
            else {
                instruments.push_back(make_shared<MusicalInstrument>(name, count));
            }

        }
        else if (choice == 2) {
            if (instruments.empty()) {
                cout << "Нет инструментов для удаления." << endl;
                continue;
            }
            cout << "Выберите инструмент по индексу:\n";
            for (size_t i = 0; i < instruments.size(); ++i)
                cout << i << ") " << instruments[i]->getName() << endl;

            int idx = getIntInput("Выбор: ", 0, instruments.size() - 1);
            instruments.erase(instruments.begin() + idx);
            cout << "Инструмент удалён." << endl;

        }
        else if (choice == 3) {
            if (instruments.empty()) {
                cout << "Список инструментов пуст." << endl;
                continue;
            }

            cout << "Выберите инструмент по индексу:\n";
            for (size_t i = 0; i < instruments.size(); ++i)
                cout << i << ") " << instruments[i]->getName() << endl;

            int index = getIntInput("Выбор: ", 0, instruments.size() - 1);
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
                    cout << "Новое имя: ";
                    getline(cin, newName);
                    instruments[index]->setName(newName);
                    break;
                }
                case 6: {
                    int newCount = getIntInput("Новое количество струн/клавиш: ", 1);
                    instruments[index]->setStringsCount(newCount);
                    break;
                }
                case 0: break;
                default: cout << "Неверный выбор." << endl;
                }
            } while (action != 0);
        }

    } while (choice != 0);

    cout << "Завершение программы.\n";
    return 0;
}
