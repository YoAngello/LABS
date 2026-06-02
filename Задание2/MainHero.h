#pragma once

#include "BaseCharacter.h"
#include "Weapon.h"
#include <vector>

class MainHero : public BaseCharacter {
private:
    string name;
    vector<Weapon> inventory;
    int currentWeaponIndex;
    static const int MAX_HP = 200;

public:
    MainHero(double x, double y, const string& heroName, int health);

    void hit(BaseEnemy* target) override;
    void add_weapon(const Weapon& w);
    void next_weapon();
    void heal(int amount);

    bool has_weapon() const;
    Weapon get_current_weapon() const;

    friend ostream& operator<<(ostream& out, const MainHero& h);
};
