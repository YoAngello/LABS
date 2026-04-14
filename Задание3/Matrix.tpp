#pragma once

#include "matrix.h"

template <typename T>
void Matrix<T>::allocateMemory() {
    data = new T*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new T[cols];
    }
}

template <typename T>
void Matrix<T>::freeMemory() {
    if (data) {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}

template <typename T>
void Matrix<T>::copyData(const Matrix& other) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

template <typename T>
Matrix<T>::Matrix(int r, int c) : rows(r), cols(c), data(nullptr) {
    if (rows > 0 && cols > 0) {
        allocateMemory();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = T(); // Инициализация значением по умолчанию
            }
        }
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    if (rows > 0 && cols > 0) {
        allocateMemory();
        copyData(other);
    } else {
        data = nullptr;
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    freeMemory();
}

template <typename T>
void Matrix<T>::Set(int i, int j, const T& value) {
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        throw out_of_range("Индекс выходит за пределы матрицы");
    }
    data[i][j] = value;
}

template <typename T>
T Matrix<T>::Get(int i, int j) const {
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        throw out_of_range("Индекс выходит за пределы матрицы");
    }
    return data[i][j];
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw invalid_argument("Размеры матриц не совпадают для сложения");
    }

    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
    if (cols != other.rows) {
        throw invalid_argument("Количество столбцов первой матрицы должно равняться количеству строк второй для умножения");
    }

    Matrix<T> result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            T sum = T(); // Нулевое значение для типа T
            for (int k = 0; k < cols; ++k) {
                sum = sum + data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

template <typename U>
ostream& operator<<(ostream& os, const Matrix<U>& m) {
    os << m.rows << " " << m.cols << endl;
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            os << m.data[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

template <typename U>
istream& operator>>(istream& is, Matrix<U>& m) {
    // Ожидаем формат: rows cols затем все элементы
    int r, c;
    is >> r >> c;
    if (r <= 0 || c <= 0) {
        throw invalid_argument("Некорректный размер матрицы");
    }

    // Освобождаем старую память и выделяем новую
    m.freeMemory();
    m.rows = r;
    m.cols = c;
    m.allocateMemory();

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            is >> m.data[i][j];
        }
    }
    return is;
}