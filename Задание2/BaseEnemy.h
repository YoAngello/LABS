#pragma once

#include "BaseCharacter.h"
#include "Weapon.h"

class BaseEnemy : public BaseCharacter {
private:
    Weapon weapon;

public:
    BaseEnemy(double x, double y, const Weapon& w, int health);

    void hit(BaseCharacter* target);
    void hit(class MainHero* target);

    friend ostream& operator<<(ostream& out, const BaseEnemy& e);
};