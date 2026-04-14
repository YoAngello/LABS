#include <iostream>
#include <string>
#include "change.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int choice = 0;
    cout << "Программа для демонстрации работы функции change." << endl;
    cout << "Выберите тип данных:" << endl;
    cout << "1 - int" << endl;
    cout << "2 - double" << endl;
    cout << "3 - string" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;

    while (choice < 1 || choice > 3) {
        cout << "Ошибка: введите 1, 2 или 3: ";
        cin >> choice;
    }

    if (choice == 1) {
        int size = 0;
        cout << "Введите размер массива (положительное целое): ";
        cin >> size;
        while (size <= 0) {
            cout << "Ошибка: размер > 0. Повторите: ";
            cin >> size;
        }

        int* arr = new int[size];
        cout << "Введите " << size << " целых чисел через пробел: ";
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
        }

        // Контрольный вывод
        cout << "Массив: ";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        int elem1, elem2;
        cout << "Введите первый элемент для обмена: ";
        cin >> elem1;
        cout << "Введите второй элемент для обмена: ";
        cin >> elem2;

        bool success = change(elem1, elem2, arr, size);

        if (success) {
            cout << "Массив после обмена: ";
            for (int i = 0; i < size; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        delete[] arr;
    }
    else if (choice == 2) {
        int size = 0;
        cout << "Введите размер массива (положительное целое): ";
        cin >> size;
        while (size <= 0) {
            cout << "Ошибка: размер > 0. Повторите: ";
            cin >> size;
        }

        double* arr = new double[size];
        cout << "Введите " << size << " вещественных чисел через пробел: ";
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
        }

        cout << "Массив: ";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        double elem1, elem2;
        cout << "Введите первый элемент для обмена: ";
        cin >> elem1;
        cout << "Введите второй элемент для обмена: ";
        cin >> elem2;

        bool success = change(elem1, elem2, arr, size);

        if (success) {
            cout << "Массив после обмена: ";
            for (int i = 0; i < size; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        delete[] arr;
    }
    else if (choice == 3) {
        int size = 0;
        cout << "Введите размер массива (положительное целое): ";
        cin >> size;
        while (size <= 0) {
            cout << "Ошибка: размер > 0. Повторите: ";
            cin >> size;
        }

        string* arr = new string[size];
        cout << "Введите " << size << " строк (через пробел): ";
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
        }

        cout << "Массив: ";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        string elem1, elem2;
        cout << "Введите первый элемент для обмена: ";
        cin >> elem1;
        cout << "Введите второй элемент для обмена: ";
        cin >> elem2;

        bool success = change(elem1, elem2, arr, size);

        if (success) {
            cout << "Массив после обмена: ";
            for (int i = 0; i < size; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        delete[] arr;
    }

    return 0;
}