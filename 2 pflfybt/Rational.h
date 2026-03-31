#pragma once

#include <iostream>

class Rational
{
private:
    int num; // Числитель
    int den; // Знаменатель

    // Приведение дроби к несократимому виду с положительным знаменателем
    void reduce();

public:
    // Конструкторы
    Rational();
    Rational(int numerator);
    Rational(int numerator, int denominator);
    Rational(const Rational& other);

    // Получение числителя и знаменателя
    int Numerator() const;
    int Denominator() const;

    // Оператор присваивания
    Rational& operator=(const Rational& other);

    // Унарные операторы
    Rational operator+() const;
    Rational operator-() const;

    // Бинарные арифметические операторы
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    // Составные операторы присваивания
    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator*=(const Rational& other);
    Rational& operator/=(const Rational& other);

    // Операторы сравнения
    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;

    // Операторы ввода и вывода
    friend std::ostream& operator<<(std::ostream& out, const Rational& r);
    friend std::istream& operator>>(std::istream& in, Rational& r);
};
