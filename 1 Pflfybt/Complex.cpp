#include "Complex.h"
#include <cmath>
#include <limits>

// Конструктор по умолчанию
Complex::Complex()
    : re(0.0), im(0.0)
{
}

// Конструктор с параметрами
Complex::Complex(double x, double y)
    : re(x), im(y)
{
}

// Конструктор копирования
Complex::Complex(const Complex& other)
    : re(other.re), im(other.im)
{
    std::cout << "[Конструктор копирования вызван]" << std::endl;
}

// Геттеры
double Complex::getRe() const
{
    return re;
}

double Complex::getIm() const
{
    return im;
}

// Модуль комплексного числа: |z| = sqrt(re^2 + im^2)
double Complex::modulus() const
{
    return std::sqrt(re * re + im * im);
}

// Перегрузка оператора присваивания
Complex& Complex::operator=(const Complex& other)
{
    std::cout << "[Оператор присваивания вызван]" << std::endl;

    // Проверка на самоприсваивание
    if (this != &other)
    {
        re = other.re;
        im = other.im;
    }
    return *this;
}

Complex Complex::operator+(const Complex& other) const
{
    return Complex(re + other.re, im + other.im);
}

// Вычитание: (a+bi) - (c+di) = (a-c) + (b-d)i
Complex Complex::operator-(const Complex& other) const
{
    return Complex(re - other.re, im - other.im);
}

// Умножение: (a+bi)*(c+di) = (ac-bd) + (ad+bc)i
Complex Complex::operator*(const Complex& other) const
{
    double newRe = re * other.re - im * other.im;
    double newIm = re * other.im + im * other.re;
    return Complex(newRe, newIm);
}

// Деление: (a+bi)/(c+di) = ((ac+bd) + (bc-ad)i) / (c^2+d^2)
Complex Complex::operator/(const Complex& other) const
{
    double denominator = other.re * other.re + other.im * other.im;

    // Защита от деления на ноль
    if (std::abs(denominator) < 1e-12)
    {
        std::cerr << "Ошибка: деление на ноль (делитель = 0+0i)!" << std::endl;
        return Complex(0.0, 0.0);
    }

    double newRe = (re * other.re + im * other.im) / denominator;
    double newIm = (im * other.re - re * other.im) / denominator;
    return Complex(newRe, newIm);
}

Complex& Complex::operator++()
{
    re += 1.0;
    im += 1.0;
    return *this;
}

// Постфиксный инкремент: z++
Complex Complex::operator++(int)
{
    Complex temp(*this); 
    re += 1.0;
    im += 1.0;
    return temp;        

// Префиксный декремент: --z
Complex& Complex::operator--()
{
    re -= 1.0;
    im -= 1.0;
    return *this;
}

// Постфиксный декремент: z--
Complex Complex::operator--(int)
{
    Complex temp(*this);
    re -= 1.0;
    im -= 1.0;
    return temp;
}

// Сравнение по модулю: >
bool Complex::operator>(const Complex& other) const
{
    return modulus() > other.modulus();
}

// Сравнение по модулю: <
bool Complex::operator<(const Complex& other) const
{
    return modulus() < other.modulus();
}

// Сравнение по модулю: == 
bool Complex::operator==(const Complex& other) const
{
    return std::abs(modulus() - other.modulus()) < 1e-9;
}

// Сравнение по модулю: !=
bool Complex::operator!=(const Complex& other) const
{
    return !(*this == other);
}

// Оператор вывода:
std::ostream& operator<<(std::ostream& out, const Complex& c)
{
    out << c.re;
    if (c.im >= 0)
        out << " + " << c.im << "*i";
    else
        out << " - " << (-c.im) << "*i";
    return out;
}

// Оператор ввода
std::istream& operator>>(std::istream& in, Complex& c)
{
    std::cout << "Введите действительную часть (re): ";
    while (!(in >> c.re))
    {
        std::cerr << "Ошибка ввода! Введите числовое значение для re: ";
        in.clear();
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Введите мнимую часть (im): ";
    while (!(in >> c.im))
    {
        std::cerr << "Ошибка ввода! Введите числовое значение для im: ";
        in.clear();
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return in;
}