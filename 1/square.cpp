#include "Square.h"
#include <sstream>

using std::stringstream;
using std::string;

Square::Square(double side) : Rectangle(side, side) {}

string Square::to_string() const {
    stringstream ss;
    ss << "{\"figure_type\":\"square\",\"side\":" << *width
        << ",\"area\":" << this->calc_area() << "}";
    return ss.str();
}