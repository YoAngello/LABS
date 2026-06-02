#pragma once

#include <iostream>
#include <string>

using namespace std;

// Собственное исключение для пустого инвентаря
class NoWeaponException : public exception {
public:
    const char* what() const noexcept override {
        return "У героя нет оружия!";
    }
};

// Собственное исключение для оружия с нулевым уроном
class ZeroDamageException : public exception {
public:
    const char* what() const noexcept override {
        return "Оружие не может иметь нулевой урон!";
    }
};

class Weapon {
private:
    string name;
    int damage;
    double range;

public:
    Weapon();
    Weapon(const string& n, int d, double r);

    string getName() const;
    int getDamage() const;
    double getRange() const;

    void setName(const string& n);
    void setDamage(int d);
    void setRange(double r);

    // Удар оружием
    void hit(class BaseCharacter* actor, class BaseCharacter* target);

    // Дружественные операторы
    friend ostream& operator<<(ostream& out, const Weapon& w);
    friend istream& operator>>(istream& in, Weapon& w);
};