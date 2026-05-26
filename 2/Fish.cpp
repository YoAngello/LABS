#include "Fish.h"

Fish::Fish(const std::string& n) : name(n) {}

Fish::~Fish() {}

void Fish::breathe() const {
    std::cout << "Fish " << name << " breathes with gills" << std::endl;
}

void Fish::eat() const {
    std::cout << "Fish " << name << " eats plankton" << std::endl;
}

void Fish::swim() const {
    std::cout << "Fish " << name << " swims in water" << std::endl;
}