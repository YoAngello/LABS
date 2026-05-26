#include "Triangle.h"
#include <sstream>
#include <cmath>

using std::stringstream;
using std::string;

Triangle::Triangle(double a, double b, double c) {
    if (a < 0) a = 0;
    if (b < 0) b = 0;
    if (c < 0) c = 0;
    if (a + b <= c || a + c <= b || b + c <= a) {
        a = b = c = 0;
    }
    this->side_a = new double(a);
    this->side_b = new double(b);
    this->side_c = new double(c);
}

Triangle::~Triangle() {
    delete side_a;
    delete side_b;
    delete side_c;
}

double Triangle::calc_area() const {
    double a = *side_a, b = *side_b, c = *side_c;
    double p = (a + b + c) / 2.0;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    if (std::isnan(area) || area < 0) area = 0;
    return area;
}

string Triangle::to_string() const {
    stringstream ss;
    ss << "{\"figure_type\":\"triangle\",\"sides\":[" << *side_a << "," << *side_b << "," << *side_c
        << "],\"area\":" << this->calc_area() << "}";
    return ss.str();
}