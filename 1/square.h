#ifndef OOP_SQUARE_H
#define OOP_SQUARE_H

#include "Rectangle.h"
#include <string>

class Square : public Rectangle {
public:
    explicit Square(double side);
    std::string to_string() const override;
};

#endif