#pragma once

#include "Rectangle.h"
#include <string>

class Square : public Rectangle {
public:
    explicit Square(double side);                    // Конструктор
    std::string to_string() const override;          // JSON
};