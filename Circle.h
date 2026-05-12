#ifndef OOP_3_CIRCLE_H
#define OOP_3_CIRCLE_H

#include <string>
#include <cmath>

#include "Figures.h"

using std::string;

class Circle : public Figure {
    double *radius;

public:
    Circle(double radius) {
        this->radius = new double(radius);
    }

    ~Circle() override {
        delete this->radius;
    }

    double calc_area() override {
        const double r = *this->radius;

        return r * r * M_PI;
    }

    string to_string() override;
};

#endif
