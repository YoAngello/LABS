#include <iostream>
#include "Complex.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    
    //---------------
    // 1. Конструкторы
    std::cout << "=== 1. Конструкторы ===" << std::endl;

    Complex a;                  // Конструктор по умолчанию
    Complex b(3.0, 4.0);       // Конструктор с параметрами
    Complex c(b);              // Конструктор копирования

    std::cout << "a (по умолчанию):    " << a << std::endl;
    std::cout << "b (3, 4):            " << b << std::endl;
    std::cout << "c (копия b):         " << c << std::endl;
    std::cout << std::endl;
    
    //----------------
    // 2. Оператор присваивания
    std::cout << "=== 2. Оператор присваивания ===" << std::endl;

    Complex d;
    d = b; // Перегруженный оператор =
    std::cout << "d = b:               " << d << std::endl;
    std::cout << std::endl;
    
    //--------------
    // 3. Ввод с клавиатуры
    std::cout << "=== 3. Ввод комплексных чисел ===" << std::endl;

    Complex z1, z2;
    std::cout << "--- Введите первое комплексное число ---" << std::endl;
    std::cin >> z1;
    std::cout << "--- Введите второе комплексное число ---" << std::endl;
    std::cin >> z2;

    // Контрольный вывод введённых данных
    std::cout << std::endl;
    std::cout << "Контрольный вывод:" << std::endl;
    std::cout << "z1 = " << z1 << std::endl;
    std::cout << "z2 = " << z2 << std::endl;
    std::cout << std::endl;

    //------------
    // 4. Арифметические операции
    std::cout << "=== 4. Арифметические операции ===" << std::endl;

    Complex sumResult = z1 + z2;
    Complex diffResult = z1 - z2;
    Complex multResult = z1 * z2;
    Complex divResult = z1 / z2;

    std::cout << "z1 + z2 = " << sumResult << std::endl;
    std::cout << "z1 - z2 = " << diffResult << std::endl;
    std::cout << "z1 * z2 = " << multResult << std::endl;
    std::cout << "z1 / z2 = " << divResult << std::endl;
    std::cout << std::endl;

    //------------
    // 5. Инкремент и декремент
    std::cout << "=== 5. Инкремент и декремент ===" << std::endl;

    Complex e(2.0, 3.0);
    std::cout << "e до операций:       " << e << std::endl;

    // Префиксный инкремент
    Complex prefInc = ++e;
    std::cout << "++e (префиксный):    " << prefInc << "   (e теперь: " << e << ")" << std::endl;

    // Постфиксный инкремент
    Complex postInc = e++;
    std::cout << "e++ (постфиксный):   " << postInc << "   (e теперь: " << e << ")" << std::endl;

    // Префиксный декремент
    Complex prefDec = --e;
    std::cout << "--e (префиксный):    " << prefDec << "   (e теперь: " << e << ")" << std::endl;

    // Постфиксный декремент
    Complex postDec = e--;
    std::cout << "e-- (постфиксный):   " << postDec << "   (e теперь: " << e << ")" << std::endl;
    std::cout << std::endl;

    //---------------
    // 6. Логические операции (сравнение по модулю)
    std::cout << "=== 6. Логические операции (сравнение по модулю) ===" << std::endl;

    std::cout << "z1 = " << z1 << "  |z1| = " << z1.modulus() << std::endl;
    std::cout << "z2 = " << z2 << "  |z2| = " << z2.modulus() << std::endl;

    std::cout << "z1 >  z2 : " << (z1 > z2 ? "true" : "false") << std::endl;
    std::cout << "z1 <  z2 : " << (z1 < z2 ? "true" : "false") << std::endl;
    std::cout << "z1 == z2 : " << (z1 == z2 ? "true" : "false") << std::endl;
    std::cout << "z1 != z2 : " << (z1 != z2 ? "true" : "false") << std::endl;
    std::cout << std::endl;

    // Дополнительный тест: числа с одинаковым модулем
    std::cout << "--- Тест: числа с одинаковым модулем ---" << std::endl;
    Complex f(3.0, 4.0);   // |f| = 5
    Complex g(4.0, 3.0);   // |g| = 5
    std::cout << "f = " << f << "  |f| = " << f.modulus() << std::endl;
    std::cout << "g = " << g << "  |g| = " << g.modulus() << std::endl;
    std::cout << "f == g : " << (f == g ? "true" : "false") << std::endl;
    std::cout << std::endl;

    //------------
    // 7. Тест деления на ноль
    std::cout << "=== 7. Тест деления на ноль ===" << std::endl;
    Complex zero;
    Complex divZeroResult = b / zero;
    std::cout << "b / 0 = " << divZeroResult << std::endl;

    std::cout << std::endl;
    std::cout << "Тестирование завершено " << std::endl;

    return 0;