#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include "print.h"

using namespace std;

int main() {
    cout << "=== ТЕСТИРОВАНИЕ ФУНКЦИИ PRINT ===\n" << endl;

    // 1. Вектор целых чисел
    vector<int> vec = { 1, 2, 3, 4, 5 };
    cout << "vector<int>: ";
    Print(vec, ", ");

    // 2. Лист строк
    list<string> lst = { "яблоко", "банан", "апельсин" };
    cout << "list<string>: ";
    Print(lst, " -> ");

    // 3. Множество чисел
    set<double> st = { 1.5, 2.7, 3.14, 4.2 };
    cout << "set<double>: ";
    Print(st, " | ");

    // 4. Вектор с одним элементом
    vector<int> single = { 42 };
    cout << "Один элемент: ";
    Print(single, ", ");

    // 5. Пустой контейнер
    vector<int> empty;
    cout << "Пустой контейнер: ";
    Print(empty, ", ");

    // 6. Вектор символов
    vector<char> chars = { 'A', 'B', 'C', 'D' };
    cout << "vector<char>: ";
    Print(chars, "");

    // 7. Разные разделители
    vector<int> nums = { 10, 20, 30, 40 };
    cout << "Разделитель ' - ': ";
    Print(nums, " - ");

    cout << "Разделитель ' * ': ";
    Print(nums, " * ");

    cout << "Без разделителя: ";
    Print(nums, "");

    return 0;
}