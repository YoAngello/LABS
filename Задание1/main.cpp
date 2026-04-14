#include <iostream>
#include <string>
#include "contains.h"

using namespace std;

int choise = 0;
cout << "Программа для проверки работы шаблонной функции contains." << endl;
cout << "Выберите тип данных:" << endl;
cout << "1 - int" << endl;
cout << "2 - double" << endl;
cout << "3 - string" << endl;
cout << "Ваш выбор: ";
cin >> choise;

// Защита от дурака
while (choice < 1 || choice > 3) {
    cout << "Ошибка: введите 1, 2 или 3: ";
    cin >> choice;
}

if (choice == 1) {
    int size = 0;
    cout << "Введите размер массива (целое положительное число): ";
    cin >> size;

    while (size <= 0) {
        cout << "Ошибка: размер должен быть > 0. Повторите ввод: ";
        cin >> size;
    }

    int* arr = new int[size];
    cout << "Введите " << size << " целых чисел через пробел: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    // Контрольный вывод
    cout << "Введённый массив: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int element;
    cout << "Введите элемент для поиска: ";
    cin >> element;

    bool result = contains(element, arr, size);
    cout << (result ? "Элемент найден." : "Элемент не найден.") << endl;

    delete[] arr;
}
else if (choice == 2) {
    int size = 0;
    cout << "Введите размер массива (целое положительное число): ";
    cin >> size;

    while (size <= 0) {
        cout << "Ошибка: размер должен быть > 0. Повторите ввод: ";
        cin >> size;
    }

    double* arr = new double[size];
    cout << "Введите " << size << " вещественных чисел через пробел: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    // Контрольный вывод
    cout << "Введённый массив: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    double element;
    cout << "Введите элемент для поиска: ";
    cin >> element;

    bool result = contains(element, arr, size);
    cout << (result ? "Элемент найден." : "Элемент не найден.") << endl;

    delete[] arr;
}
else if (choice == 3) {
    int size = 0;
    cout << "Введите размер массива (целое положительное число): ";
    cin >> size;

    while (size <= 0) {
        cout << "Ошибка: размер должен быть > 0. Повторите ввод: ";
        cin >> size;
    }

    string* arr = new string[size];
    cout << "Введите " << size << " строк (каждая строка вводится с новой строки или через пробел? Через пробел): ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    // Контрольный вывод
    cout << "Введённый массив: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    string element;
    cout << "Введите элемент для поиска: ";
    cin >> element;

    bool result = contains(element, arr, size);
    cout << (result ? "Элемент найден." : "Элемент не найден.") << endl;

    delete[] arr;
}

return 0;
}
