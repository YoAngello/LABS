#pragma once
#include <iostream>

class Complex
{
private:
    double re; // Действительная часть комплексного числа
    double im; // Мнимая часть комплексного числа

public:
    // --- Конструкторы ---
    Complex();                          // Конструктор по умолчанию
    Complex(double x, double y);        // Конструктор с параметрами
    Complex(const Complex& other);      // Конструктор копирования

    // --- Геттеры ---
    double getRe() const;
    double getIm() const;

    // --- Модуль комплексного числа ---
    double modulus() const;

    // --- Перегрузка оператора присваивания ---
    Complex& operator=(const Complex& other);

    // --- Арифметические операторы ---
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    // --- Инкремент ---
    Complex& operator++();       // Префиксный инкремент
    Complex  operator++(int);    // Постфиксный инкремент

    // --- Декремент ---
    Complex& operator--();       // Префиксный декремент
    Complex  operator--(int);    // Постфиксный декремент

    // --- Логические операторы (сравнение по модулю) ---
    bool operator>(const Complex& other)  const;
    bool operator<(const Complex& other)  const;
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    // --- Операторы ввода/вывода ---
    friend std::ostream& operator<<(std::ostream& out, const Complex& c);
    friend std::istream& operator>>(std::istream& in, Complex& c);
};
