#include "BaseCharacter.h"
#include "BaseEnemy.h"

BaseCharacter::BaseCharacter() : pos_x(0), pos_y(0), hp(100), alive(true) {}

BaseCharacter::BaseCharacter(double x, double y, int health)
    : pos_x(x), pos_y(y), hp(health), alive(health > 0) {
}

void BaseCharacter::move(double delta_x, double delta_y) {
    pos_x += delta_x;
    pos_y += delta_y;
    cout << "Переместился на (" << delta_x << ", " << delta_y
        << "). Теперь на (" << pos_x << ", " << pos_y << ")" << endl;
}

bool BaseCharacter::is_alive() const {
    return alive;
}

void BaseCharacter::get_damage(int amount) {
    hp -= amount;
    if (hp <= 0) {
        hp = 0;
        alive = false;
        cout << "Персонаж погиб!" << endl;
    }
}

double BaseCharacter::get_x() const { return pos_x; }
double BaseCharacter::get_y() const { return pos_y; }
int BaseCharacter::get_hp() const { return hp; }