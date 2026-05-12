#ifndef OOP_TRIANGLE_H
#define OOP_TRIANGLE_H

#include "Figures.h"
#include <string>

// Класс "Треугольник" (по трём сторонам, формула Герона)
class Triangle : public Figure {
private:
    double* side_a;
    double* side_b;
    double* side_c;

public:
    Triangle(double a, double b, double c);
    ~Triangle() override;

    double calc_area() const override;
    std::string to_string() const override;
};

#endif