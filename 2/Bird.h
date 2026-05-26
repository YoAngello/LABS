#pragma once

#include "Animal.h"

class Bird : public Animal {
private:
    std::string name;

public:
    Bird(const std::string& n);
    ~Bird();

    void breathe() const override;
    void eat() const override;
    void lay_eggs() const;
};