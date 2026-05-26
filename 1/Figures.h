#pragma once

#include <string>

class Figure {
public:
    virtual ~Figure() = default;                    // Виртуальный деструктор
    virtual double calc_area() const = 0;           // Вычисляет площадь
    virtual std::string to_string() const = 0;      // JSON в строку
};

double calc_cylinder_volume(const Figure* base, double height);  // Объём цилиндра