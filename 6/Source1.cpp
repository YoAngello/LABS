#include <algorithm>
#include <vector>
#include <iostream>

template <typename T>
void Process(const std::vector<T>& data) {
    std::vector<T> filtered;

    // Вариант 1: Использование std::back_inserter
    auto filteredLast = std::copy_if(
        data.begin(),
        data.end(),
        std::back_inserter(filtered),  // ← ИСПРАВЛЕНО
        [](const T& x) { return x > 0; }
    );

    PrintResults(filtered.begin(), filtered.end());  // ← ИСПРАВЛЕНО (используем end())
}

// Вариант 2: Альтернативный подход с reserve для оптимизации
template <typename T>
void ProcessOptimized(const std::vector<T>& data) {
    std::vector<T> filtered;
    filtered.reserve(data.size());  // Оптимизация: заранее выделяем память

    auto filteredLast = std::copy_if(
        data.begin(),
        data.end(),
        std::back_inserter(filtered),
        [](const T& x) { return x > 0; }
    );

    PrintResults(filtered.begin(), filtered.end());
}