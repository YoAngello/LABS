//
// Created by ivan on 3/3/26.
//

#include <sstream>

#include "Rectangle.h"

using std::stringstream;

string Rectangle::to_string() {
    stringstream ss;

    ss << "{"
            << "\n\t"
            << "\"figure_type\": \"rectangle\","
            << "\n\t"
            << "\"area\": " << this->calc_area()
            << "\n"
            << "}";

    return ss.str();
}
