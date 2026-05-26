#pragma once

#include "Animal.h"

class Fish : public Animal {
private:
    std::string name;

public:
    Fish(const std::string& n);
    ~Fish();

    void breathe() const override;
    void eat() const override;
    void swim() const;
};