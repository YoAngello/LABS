#include <iostream>
#include <stdexcept>
#include "Rational.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    // 1. Конструкторы
    std::cout << "=== 1. Конструкторы ===" << std::endl;

    Rational a;
    Rational b(5);
    Rational c(6, 4);
    Rational d(-3, -9);
    Rational e(4, -6);

    std::cout << "a (по умолчанию):     " << a << std::endl;
    std::cout << "b (5):                " << b << std::endl;
    std::cout << "c (6/4):              " << c << std::endl;
    std::cout << "  c.Numerator() = " << c.Numerator()
        << ", c.Denominator() = " << c.Denominator() << std::endl;
    std::cout << "d (-3/-9):            " << d << std::endl;
    std::cout << "e (4/-6):             " << e << std::endl;
    std::cout << std::endl;

    // 2. Конструктор копирования и присваивание
    std::cout << "=== 2. Копирование и присваивание ===" << std::endl;

    Rational f(c);
    std::cout << "f (копия c):          " << f << std::endl;

    Rational g;
    g = c;
    std::cout << "g = c:                " << g << std::endl;
    std::cout << std::endl;

    // 3. Ввод с клавиатуры
    std::cout << "=== 3. Ввод рациональных чисел ===" << std::endl;

    Rational r1, r2;
    std::cout << "Введите первую дробь:" << std::endl;
    std::cin >> r1;
    std::cout << "Введите вторую дробь:" << std::endl;
    std::cin >> r2;

    std::cout << std::endl;
    std::cout << "Контрольный вывод:" << std::endl;
    std::cout << "r1 = " << r1 << std::endl;
    std::cout << "r2 = " << r2 << std::endl;
    std::cout << std::endl;

    // 4. Арифметические операции между Rational
    std::cout << "=== 4. Арифметические операции (Rational и Rational) ===" << std::endl;

    std::cout << "r1 + r2 = " << (r1 + r2) << std::endl;
    std::cout << "r1 - r2 = " << (r1 - r2) << std::endl;
    std::cout << "r1 * r2 = " << (r1 * r2) << std::endl;

    try
    {
        std::cout << "r1 / r2 = " << (r1 / r2) << std::endl;
    }
    catch (const std::invalid_argument& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    std::cout << std::endl;

    // 5. Арифметические операции с int
    std::cout << "=== 5. Арифметические операции (Rational и int) ===" << std::endl;

    Rational h(1, 3);
    std::cout << "h = " << h << std::endl;

    std::cout << "h + 2 = " << (h + 2) << std::endl;
    std::cout << "h - 1 = " << (h - 1) << std::endl;
    std::cout << "h * 3 = " << (h * 3) << std::endl;
    std::cout << "h / 2 = " << (h / 2) << std::endl;
    std::cout << "2 + h = " << (2 + h) << std::endl;
    std::cout << "6 * h = " << (6 * h) << std::endl;
    std::cout << std::endl;

    // 6. Унарные операторы
    std::cout << "=== 6. Унарные операторы ===" << std::endl;

    Rational k(3, 7);
    std::cout << "k  = " << k << std::endl;
    std::cout << "+k = " << +k << std::endl;
    std::cout << "-k = " << -k << std::endl;
    std::cout << std::endl;

    // 7. Составные операторы
    std::cout << "=== 7. Составные операторы ===" << std::endl;

    Rational m(1, 2);
    std::cout << "m = " << m << std::endl;

    m += Rational(1, 3);
    std::cout << "m += 1/3:  m = " << m << std::endl;

    m -= Rational(1, 6);
    std::cout << "m -= 1/6:  m = " << m << std::endl;

    m *= Rational(3, 4);
    std::cout << "m *= 3/4:  m = " << m << std::endl;

    m /= Rational(1, 2);
    std::cout << "m /= 1/2:  m = " << m << std::endl;

    m += 3;
    std::cout << "m += 3:    m = " << m << std::endl;

    m *= 2;
    std::cout << "m *= 2:    m = " << m << std::endl;
    std::cout << std::endl;

    // 8. Операторы сравнения
    std::cout << "=== 8. Операторы сравнения ===" << std::endl;

    Rational p(1, 2);
    Rational q(2, 4);
    Rational s(3, 4);

    std::cout << "p = " << p << ", q = " << q << ", s = " << s << std::endl;
    std::cout << "p == q : " << (p == q ? "true" : "false") << std::endl;
    std::cout << "p != q : " << (p != q ? "true" : "false") << std::endl;
    std::cout << "p == s : " << (p == s ? "true" : "false") << std::endl;
    std::cout << "p != s : " << (p != s ? "true" : "false") << std::endl;

    Rational t(6, 3);
    std::cout << "t = " << t << std::endl;
    std::cout << "t == 2 : " << (t == 2 ? "true" : "false") << std::endl;
    std::cout << "t != 3 : " << (t != 3 ? "true" : "false") << std::endl;
    std::cout << std::endl;

    // 9. Тест деления на ноль
    std::cout << "=== 9. Тест деления на ноль ===" << std::endl;

    try
    {
        Rational bad(1, 0);
    }
    catch (const std::invalid_argument& ex)
    {
        std::cerr << "Конструктор: " << ex.what() << std::endl;
    }

    try
    {
        Rational x(1, 2);
        Rational zero(0);
        Rational res = x / zero;
    }
    catch (const std::invalid_argument& ex)
    {
        std::cerr << "Деление:     " << ex.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== Тестирование завершено ===" << std::endl;

    return 0;
}