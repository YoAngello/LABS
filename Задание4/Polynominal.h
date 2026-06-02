#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

template<typename T>
class Polynomial {
private:
    std::vector<T> coeffs;  // Коэффициенты от младшей степени к старшей

    void trim();  // Удаление ведущих нулей

public:
    // Конструкторы
    Polynomial();                           // Нулевой многочлен
    Polynomial(const T& c);                 // Многочлен нулевой степени
    Polynomial(const std::vector<T>& coefficients);  // Из вектора

    // Степень многочлена
    int Degree() const;

    // Доступ к коэффициенту по степени
    T operator[](int power) const;

    // Вычисление значения в точке (схема Горнера)
    T operator()(const T& x) const;

    // Операторы сравнения
    bool operator==(const Polynomial& other) const;
    bool operator!=(const Polynomial& other) const;

    // Составные операторы присваивания
    Polynomial& operator+=(const Polynomial& other);
    Polynomial& operator-=(const Polynomial& other);
    Polynomial& operator*=(const Polynomial& other);

    // Бинарные арифметические операторы
    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;
};

// Скаляр + многочлен
template<typename T>
Polynomial<T> operator+(const T& scalar, const Polynomial<T>& poly);

// Многочлен + скаляр
template<typename T>
Polynomial<T> operator+(const Polynomial<T>& poly, const T& scalar);

// Скаляр - многочлен
template<typename T>
Polynomial<T> operator-(const T& scalar, const Polynomial<T>& poly);

// Многочлен - скаляр
template<typename T>
Polynomial<T> operator-(const Polynomial<T>& poly, const T& scalar);

// Скаляр * многочлен
template<typename T>
Polynomial<T> operator*(const T& scalar, const Polynomial<T>& poly);

// Многочлен * скаляр
template<typename T>
Polynomial<T> operator*(const Polynomial<T>& poly, const T& scalar);

// Оператор вывода
template<typename T>
std::ostream& operator<<(std::ostream& out, const Polynomial<T>& poly);

#include "Polynomial.tpp"  // Подключаем реализацию
