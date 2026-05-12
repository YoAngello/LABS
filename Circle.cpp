#include <sstream>

#include "Circle.h"

using std::stringstream;

string Circle::to_string()  {
    stringstream ss;

    ss << "{"
            << "\n\t"
            << "\"figure_type\": \"circle\","
            << "\n\t"
            << "\"area\": " << this->calc_area()
            << "\n"
            << "}";

    return ss.str();
}
