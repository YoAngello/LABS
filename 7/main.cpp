#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "Unique.h"

using namespace std;

// Функция для печати диапазона
template <typename Iter>
void PrintRange(Iter first, Iter last) {
    for (Iter it = first; it != last; ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    cout << "=== ТЕСТИРОВАНИЕ UNIQUE ===\n" << endl;

    // Тест 1: Вектор целых чисел
    cout << "Тест 1: Вектор int" << endl;
    vector<int> v1 = { 1, 1, 2, 2, 2, 3, 4, 4, 5, 5, 5, 5 };
    cout << "Исходный: ";
    PrintRange(v1.begin(), v1.end());

    auto newEnd = Unique(v1.begin(), v1.end());
    cout << "После Unique: ";
    PrintRange(v1.begin(), newEnd);
    cout << "Размер после обработки: " << distance(v1.begin(), newEnd) << endl;
    cout << endl;

    // Тест 2: Вектор с одним элементом
    cout << "Тест 2: Один элемент" << endl;
    vector<int> v2 = { 42 };
    cout << "Исходный: ";
    PrintRange(v2.begin(), v2.end());

    auto newEnd2 = Unique(v2.begin(), v2.end());
    cout << "После Unique: ";
    PrintRange(v2.begin(), newEnd2);
    cout << endl;

    // Тест 3: Пустой вектор
    cout << "Тест 3: Пустой вектор" << endl;
    vector<int> v3;
    cout << "Пустой вектор" << endl;

    auto newEnd3 = Unique(v3.begin(), v3.end());
    if (newEnd3 == v3.end()) {
        cout << "Итератор вернул end() - корректно" << endl;
    }
    cout << endl;

    // Тест 4: Все элементы одинаковые
    cout << "Тест 4: Все элементы одинаковые" << endl;
    vector<int> v4 = { 7, 7, 7, 7, 7 };
    cout << "Исходный: ";
    PrintRange(v4.begin(), v4.end());

    auto newEnd4 = Unique(v4.begin(), v4.end());
    cout << "После Unique: ";
    PrintRange(v4.begin(), newEnd4);
    cout << endl;

    // Тест 5: Все элементы уже уникальны
    cout << "Тест 5: Все элементы уникальны" << endl;
    vector<int> v5 = { 1, 2, 3, 4, 5 };
    cout << "Исходный: ";
    PrintRange(v5.begin(), v5.end());

    auto newEnd5 = Unique(v5.begin(), v5.end());
    cout << "После Unique: ";
    PrintRange(v5.begin(), newEnd5);
    cout << endl;

    // Тест 6: Строки
    cout << "Тест 6: Вектор строк" << endl;
    vector<string> v6 = { "apple", "apple", "banana", "banana", "banana", "cherry" };
    cout << "Исходный: ";
    PrintRange(v6.begin(), v6.end());

    auto newEnd6 = Unique(v6.begin(), v6.end());
    cout << "После Unique: ";
    PrintRange(v6.begin(), newEnd6);
    cout << endl;

    // Тест 7: list (проверка работы с разными контейнерами)
    cout << "Тест 7: list (разные итераторы)" << endl;
    list<int> lst = { 1, 1, 1, 2, 3, 3, 4, 4, 4, 4, 5 };
    cout << "Исходный: ";
    PrintRange(lst.begin(), lst.end());

    auto newEnd7 = Unique(lst.begin(), lst.end());
    cout << "После Unique: ";
    PrintRange(lst.begin(), newEnd7);
    cout << endl;

    // Тест 8: Демонстрация части диапазона
    cout << "Тест 8: Обработка части вектора" << endl;
    vector<int> v8 = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5 };
    cout << "Исходный: ";
    PrintRange(v8.begin(), v8.end());

    // Обрабатываем только элементы с индексами 2-7
    auto newEnd8 = Unique(v8.begin() + 2, v8.begin() + 8);
    cout << "После Unique (элементы 2-7): ";
    PrintRange(v8.begin(), newEnd8);
    cout << "Оставшаяся часть: ";
    PrintRange(newEnd8, v8.end());

    return 0;
}