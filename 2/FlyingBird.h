#pragma once

#include "Bird.h"

class FlyingBird : public Bird {
private:
    std::string name;

public:
    FlyingBird(const std::string& n);
    ~FlyingBird();

    void fly() const;
};