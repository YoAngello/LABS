#pragma once

#include <string>
#include "Figures.h"

class Rectangle : public Figure {
protected:
    double* width;                                   // Указатель на ширину
    double* height;                                  // Указатель на высоту

public:
    Rectangle(double width, double height);          // Конструктор
    ~Rectangle() override;                           // Деструктор
    double calc_area() const override;               // Площадь
    std::string to_string() const override;          // JSON
};