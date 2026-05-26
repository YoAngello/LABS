#include "Circle.h"
#include <sstream>
#include <cmath>

using std::stringstream;
using std::string;

Circle::Circle(double radius) {
    if (radius < 0) radius = 0;
    this->radius = new double(radius);
}

Circle::~Circle() {
    delete radius;
}

double Circle::calc_area() const {
    return M_PI * (*radius) * (*radius);
}

string Circle::to_string() const {
    stringstream ss;
    ss << "{\"figure_type\":\"circle\",\"radius\":" << *radius
        << ",\"area\":" << this->calc_area() << "}";
    return ss.str();
}