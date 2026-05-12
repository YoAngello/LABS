#include "Square.h"
#include <sstream>

using std::stringstream;
using std::string;

Square::Square(double side) : Rectangle(side, side) {}

string Square::to_string() const {
    stringstream ss;
    ss << "{"
       << "\n\t"
       << "\"figure_type\": \"square\","
       << "\n\t"
       << "\"area\": " << this->calc_area()
       << "\n"
       << "}";
    return ss.str();
}