#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class BaseCharacter {
protected:
    double pos_x;
    double pos_y;
    int hp;
    bool alive;

public:
    BaseCharacter();
    BaseCharacter(double x, double y, int health);
    virtual ~BaseCharacter() = default;

    void move(double delta_x, double delta_y);
    bool is_alive() const;
    void get_damage(int amount);

    double get_x() const;
    double get_y() const;
    int get_hp() const;

    virtual void hit(class BaseEnemy* target) = 0;
};
