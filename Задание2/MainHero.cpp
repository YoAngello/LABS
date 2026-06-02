#include "MainHero.h"
#include "BaseEnemy.h"

MainHero::MainHero(double x, double y, const string& heroName, int health)
    : BaseCharacter(x, y, min(health, MAX_HP)), name(heroName), currentWeaponIndex(-1) {
}

void MainHero::hit(BaseEnemy* target) {
    if (!is_alive()) {
        cout << "Герой мёртв и не может атаковать!" << endl;
        return;
    }

    if (!has_weapon()) {
        cout << "Я безоружен" << endl;
        return;
    }

    if (!target->is_alive()) {
        cout << "Враг уже мёртв!" << endl;
        return;
    }

    Weapon& w = inventory[currentWeaponIndex];
    w.hit(this, target);
}

void MainHero::add_weapon(const Weapon& w) {
    inventory.push_back(w);
    cout << "Подобрал " << w << endl;

    if (currentWeaponIndex == -1) {
        currentWeaponIndex = 0;
        cout << "Оружие экипировано!" << endl;
    }
}

void MainHero::next_weapon() {
    if (!has_weapon()) {
        cout << "Я безоружен" << endl;
        return;
    }

    if (inventory.size() == 1) {
        cout << "У меня только одно оружие" << endl;
        return;
    }

    currentWeaponIndex = (currentWeaponIndex + 1) % inventory.size();
    cout << "Сменил оружие на " << inventory[currentWeaponIndex] << endl;
}

void MainHero::heal(int amount) {
    if (!is_alive()) {
        cout << "Герой мёртв, лечение невозможно!" << endl;
        return;
    }

    hp = min(hp + amount, MAX_HP);
    cout << "Полечился, теперь здоровья " << hp << endl;
}

bool MainHero::has_weapon() const {
    return !inventory.empty() && currentWeaponIndex != -1;
}

Weapon MainHero::get_current_weapon() const {
    if (has_weapon()) {
        return inventory[currentWeaponIndex];
    }
    throw NoWeaponException();
}

ostream& operator<<(ostream& out, const MainHero& h) {
    out << "Герой " << h.name << " на позиции (" << h.pos_x << ", " << h.pos_y
        << "), HP: " << h.hp;
    if (h.has_weapon()) {
        out << ", оружие: " << h.inventory[h.currentWeaponIndex];
    }
    else {
        out << ", без оружия";
    }
    return out;
}