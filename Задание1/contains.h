#pragma once

template <typename T>
bool contains(const T& element, const T* array, int size);
bool contains(const T& element, const T* array, int size) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == element) {
            return true;
        }
    }
    return false;
}