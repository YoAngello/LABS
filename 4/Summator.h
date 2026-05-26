#pragma once

class Summator {
public:
    // Виртуальный деструктор
    virtual ~Summator() {}

    // Виртуальный метод преобразования элемента последовательности
    // Для базового класса возвращает само число (тождественное преобразование)
    virtual int transform(int i) const;

    // Вычисляет сумму transform(1) + transform(2) + ... + transform(N)
    // Реализован в базовом классе, не переопределяется в производных
    long long sum(int N) const;
};
