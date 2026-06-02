#pragma once

#include <iostream>

// Шаблонная функция для печати элементов контейнера
template<typename Container>
void Print(const Container& container, const std::string& separator) {
    bool first = true;

    for (const auto& element : container) {
        if (!first) {
            std::cout << separator;
        }
        std::cout << element;
        first = false;
    }

    std::cout << std::endl;
}