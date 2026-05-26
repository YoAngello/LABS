#pragma once

#include <string>
#include "Figures.h"

class Circle : public Figure {
private:
    double* radius;                                  // Указатель на радиус

public:
    explicit Circle(double radius);                  // Конструктор
    ~Circle() override;                              // Деструктор
    double calc_area() const override;               // Площадь
    std::string to_string() const override;          // JSON
};