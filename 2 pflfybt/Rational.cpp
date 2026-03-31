#include "Rational.h"
#include <numeric>
#include <cmath>
#include <stdexcept>
#include <limits>

// Приведение дроби к несократимому виду
void Rational::reduce()
{
    if (num == 0)
    {
        den = 1;
        return;
    }

    // Знаменатель всегда положительный
    if (den < 0)
    {
        num = -num;
        den = -den;
    }

    // Сокращение по НОД
    int gcd = std::gcd(std::abs(num), std::abs(den));
    num /= gcd;
    den /= gcd;
}

// Конструктор по умолчанию
Rational::Rational()
    : num(0), den(1)
{
}

// Конструктор из целого числа
Rational::Rational(int numerator)
    : num(numerator), den(1)
{
}

// Конструктор с числителем и знаменателем
Rational::Rational(int numerator, int denominator)
    : num(numerator), den(denominator)
{
    if (denominator == 0)
    {
        throw std::invalid_argument("Ошибка: знаменатель не может быть равен нулю!");
    }
    reduce();
}

// Конструктор копирования
Rational::Rational(const Rational& other)
    : num(other.num), den(other.den)
{
    std::cout << "[Конструктор копирования Rational вызван]" << std::endl;
}

// Получение числителя
int Rational::Numerator() const
{
    return num;
}

// Получение знаменателя
int Rational::Denominator() const
{
    return den;
}

// Оператор присваивания
Rational& Rational::operator=(const Rational& other)
{
    if (this != &other)
    {
        num = other.num;
        den = other.den;
    }
    return *this;
}

// Унарный плюс
Rational Rational::operator+() const
{
    return *this;
}

// Унарный минус
Rational Rational::operator-() const
{
    return Rational(-num, den);
}

// Сложение: a/b + c/d = (a*d + c*b) / (b*d)
Rational Rational::operator+(const Rational& other) const
{
    int newNum = num * other.den + other.num * den;
    int newDen = den * other.den;
    return Rational(newNum, newDen);
}

// Вычитание: a/b - c/d = (a*d - c*b) / (b*d)
Rational Rational::operator-(const Rational& other) const
{
    int newNum = num * other.den - other.num * den;
    int newDen = den * other.den;
    return Rational(newNum, newDen);
}

// Умножение: (a/b) * (c/d) = (a*c) / (b*d)
Rational Rational::operator*(const Rational& other) const
{
    int newNum = num * other.num;
    int newDen = den * other.den;
    return Rational(newNum, newDen);
}

// Деление: (a/b) / (c/d) = (a*d) / (b*c)
Rational Rational::operator/(const Rational& other) const
{
    if (other.num == 0)
    {
        throw std::invalid_argument("Ошибка: деление на ноль!");
    }
    int newNum = num * other.den;
    int newDen = den * other.num;
    return Rational(newNum, newDen);
}

// Оператор +=
Rational& Rational::operator+=(const Rational& other)
{
    *this = *this + other;
    return *this;
}

// Оператор -=
Rational& Rational::operator-=(const Rational& other)
{
    *this = *this - other;
    return *this;
}

// Оператор *=
Rational& Rational::operator*=(const Rational& other)
{
    *this = *this * other;
    return *this;
}

// Оператор /=
Rational& Rational::operator/=(const Rational& other)
{
    *this = *this / other;
    return *this;
}

// Оператор ==
bool Rational::operator==(const Rational& other) const
{
    return (num == other.num) && (den == other.den);
}

// Оператор !=
bool Rational::operator!=(const Rational& other) const
{
    return !(*this == other);
}

// Оператор вывода
std::ostream& operator<<(std::ostream& out, const Rational& r)
{
    if (r.den == 1)
    {
        out << r.num;
    }
    else
    {
        out << r.num << "/" << r.den;
    }
    return out;
}

// Оператор ввода
std::istream& operator>>(std::istream& in, Rational& r)
{
    int numerator = 0;
    int denominator = 1;

    std::cout << "Введите числитель: ";
    while (!(in >> numerator))
    {
        std::cerr << "Ошибка! Введите целое число для числителя: ";
        in.clear();
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Введите знаменатель (не 0): ";
    while (true)
    {
        if (!(in >> denominator))
        {
            std::cerr << "Ошибка! Введите целое число для знаменателя: ";
            in.clear();
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (denominator == 0)
        {
            std::cerr << "Знаменатель не может быть нулём! Повторите ввод: ";
            continue;
        }
        break;
    }

    r = Rational(numerator, denominator);
    return in;
}