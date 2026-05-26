#include "FlyingBird.h"

FlyingBird::FlyingBird(const std::string& n) : Bird(n), name(n) {}

FlyingBird::~FlyingBird() {}

void FlyingBird::fly() const {
    std::cout << "Bird " << name << " flies in the sky" << std::endl;
}