#pragma once

#include <algorithm>

template <typename Iter>
Iter Unique(Iter first, Iter last) {
    if (first == last) {
        return last;  // Пустой диапазон
    }

    Iter write = first;      // Куда пишем следующий уникальный элемент
    Iter read = first;       // Откуда читаем
    ++read;                  // Начинаем со второго элемента

    while (read != last) {
        // Если текущий элемент отличается от последнего записанного
        if (!(*write == *read)) {
            ++write;
            *write = *read;
        }
        ++read;
    }

    // Возвращаем итератор за последний уникальный элемент
    return ++write;
}
