#pragma once

#include <iostream>
#include "contains.h"

using namespace std;

template <typename T>
bool change(const T& elem1, const T& elem2, T* array, int size) {
    // Проверка наличия обоих элементов в массиве
    if (!contains(elem1, array, size)) {
        cout << "Ошибка: элемент \"" << elem1 << "\" не найден в массиве." << endl;
        return false;
    }
    if (!contains(elem2, array, size)) {
        cout << "Ошибка: элемент \"" << elem2 << "\" не найден в массиве." << endl;
        return false;
    }

    // Поиск индексов элементов
    int index1 = -1, index2 = -1;
    for (int i = 0; i < size; ++i) {
        if (array[i] == elem1) index1 = i;
        if (array[i] == elem2) index2 = i;
    }

    // Обмен местами
    if (index1 != index2) {
        T temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
        cout << "Успешно: элементы \"" << elem1 << "\" и \"" << elem2 << "\" обменяны местами." << endl;
    }
    else {
        cout << "Предупреждение: элементы совпадают, обмен не требуется." << endl;
    }
    return true;
}