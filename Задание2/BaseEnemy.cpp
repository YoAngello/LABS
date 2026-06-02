#include "BaseEnemy.h"
#include "MainHero.h"

BaseEnemy::BaseEnemy(double x, double y, const Weapon& w, int health)
    : BaseCharacter(x, y, health), weapon(w) {
}

void BaseEnemy::hit(BaseCharacter* target) {
    if (!is_alive()) {
        cout << "¬раг мЄртв и не может атаковать!" << endl;
        return;
    }
    weapon.hit(this, target);
}

void BaseEnemy::hit(MainHero* target) {
    hit(static_cast<BaseCharacter*>(target));
}

ostream& operator<<(ostream& out, const BaseEnemy& e) {
    out << "¬раг на позиции (" << e.pos_x << ", " << e.pos_y
        << ") с оружием " << e.weapon;
    return out;
}