#pragma once

#include "Figures.h"
#include <string>

class Triangle : public Figure {
private:
    double* side_a;
    double* side_b;
    double* side_c;

public:
    Triangle(double a, double b, double c);          // Конструктор
    ~Triangle() override;                            // Деструктор
    double calc_area() const override;               // Площадь
    std::string to_string() const override;          
};