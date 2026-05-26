#include "Bird.h"

Bird::Bird(const std::string& n) : name(n) {}

Bird::~Bird() {}

void Bird::breathe() const {
    std::cout << "Bird " << name << " breathes with lungs" << std::endl;
}

void Bird::eat() const {
    std::cout << "Bird " << name << " pecks grains" << std::endl;
}

void Bird::lay_eggs() const {
    std::cout << "Bird " << name << " lays eggs" << std::endl;
}