#include "Rectangle.h"
#include <sstream>

using std::stringstream;
using std::string;

Rectangle::Rectangle(double width, double height) {
    if (width < 0) width = 0;
    if (height < 0) height = 0;
    this->width = new double(width);
    this->height = new double(height);
}

Rectangle::~Rectangle() {
    delete width;
    delete height;
}

double Rectangle::calc_area() const {
    return *width * *height;
}

string Rectangle::to_string() const {
    stringstream ss;
    ss << "{\"figure_type\":\"rectangle\",\"width\":" << *width
        << ",\"height\":" << *height
        << ",\"area\":" << this->calc_area() << "}";
    return ss.str();
}