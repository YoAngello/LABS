#pragma once

#include <iostream>

class Animal {
public:
    virtual ~Animal() {}

    virtual void breathe() const = 0;
    virtual void eat() const = 0;
};