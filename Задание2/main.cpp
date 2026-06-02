#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Weapon.h"
#include "BaseCharacter.h"
#include "BaseEnemy.h"
#include "MainHero.h"

using namespace std;

void printSeparator() {
    cout << "\n========================================\n" << endl;
}

void battle() {
    cout << "=== БИТВА ГЕРОЯ С ВРАГАМИ ===\n" << endl;

    try {
        // Создаём оружие для героя
        Weapon sword("Меч", 25, 3.0);
        Weapon bow("Лук", 15, 8.0);
        Weapon axe("Топор", 30, 2.0);

        // Создаём героя
        MainHero hero(0, 0, "Артур", 150);
        hero.add_weapon(sword);
        hero.add_weapon(bow);

        cout << hero << endl;

        // Создаём врагов
        Weapon enemyWeapon1("Коготь", 10, 2.0);
        Weapon enemyWeapon2("Дубина", 20, 1.5);
        Weapon enemyWeapon3("Лук орка", 12, 6.0);

        vector<BaseEnemy*> enemies;
        enemies.push_back(new BaseEnemy(2, 2, enemyWeapon1, 60));
        enemies.push_back(new BaseEnemy(5, 5, enemyWeapon2, 80));
        enemies.push_back(new BaseEnemy(8, 1, enemyWeapon3, 50));

        for (auto e : enemies) {
            cout << *e << endl;
        }

        printSeparator();

        // Битва
        for (auto enemy : enemies) {
            cout << "=== БОЙ С " << *enemy << " ===" << endl;

            while (hero.is_alive() && enemy->is_alive()) {
                // Герой атакует
                hero.hit(enemy);

                if (!enemy->is_alive()) {
                    cout << "Враг повержен! Слава герою!" << endl;
                    break;
                }

                // Враг атакует
                enemy->hit(&hero);

                if (!hero.is_alive()) {
                    cout << "Герой погиб в бою..." << endl;
                    break;
                }

                cout << hero << endl;
                cout << *enemy << endl;
                cout << "---" << endl;
            }
            printSeparator();
        }

        // Освобождаем память
        for (auto e : enemies) {
            delete e;
        }
    }
    catch (const NoWeaponException& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
    catch (const ZeroDamageException& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Неизвестная ошибка: " << e.what() << endl;
    }
}

void interactiveMode() {
    cout << "=== ИНТЕРАКТИВНЫЙ РЕЖИМ ===\n" << endl;

    try {
        MainHero hero(0, 0, "Герой", 100);
        cout << "Создан герой: " << hero << endl;

        int choice;
        do {
            cout << "\n--- МЕНЮ ---" << endl;
            cout << "1. Добавить оружие" << endl;
            cout << "2. Сменить оружие" << endl;
            cout << "3. Атаковать врага" << endl;
            cout << "4. Переместиться" << endl;
            cout << "5. Вылечиться" << endl;
            cout << "6. Показать статус" << endl;
            cout << "7. Создать врага и битва" << endl;
            cout << "0. Выход" << endl;
            cout << "Выбор: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                Weapon w;
                cin >> w;
                hero.add_weapon(w);
                break;
            }
            case 2:
                hero.next_weapon();
                break;
            case 3: {
                double x, y;
                int hp;
                string wname;
                int dmg;
                double range;

                cout << "Введите позицию врага (x y): ";
                cin >> x >> y;
                cout << "Введите HP врага: ";
                cin >> hp;
                cout << "Введите оружие врага (название урон дальность): ";
                cin >> wname >> dmg >> range;

                Weapon enemyWeapon(wname, dmg, range);
                BaseEnemy enemy(x, y, enemyWeapon, hp);

                cout << "Создан: " << enemy << endl;

                while (hero.is_alive() && enemy.is_alive()) {
                    hero.hit(&enemy);
                    if (!enemy.is_alive()) break;
                    enemy.hit(&hero);
                }

                if (!hero.is_alive()) {
                    cout << "Игра окончена! Герой погиб." << endl;
                    choice = 0;
                }
                break;
            }
            case 4: {
                double dx, dy;
                cout << "Введите смещение (dx dy): ";
                cin >> dx >> dy;
                hero.move(dx, dy);
                break;
            }
            case 5: {
                int amount;
                cout << "Введите количество HP для лечения: ";
                cin >> amount;
                hero.heal(amount);
                break;
            }
            case 6:
                cout << hero << endl;
                break;
            case 7:
                battle();
                break;
            case 0:
                cout << "До свидания!" << endl;
                break;
            default:
                cout << "Неверный выбор!" << endl;
            }
        } while (choice != 0);
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
}

int main() {
    srand(time(nullptr));

    cout << "=== ИГРОВАЯ СИСТЕМА ===\n" << endl;

    int mode;
    cout << "Выберите режим:\n";
    cout << "1. Автоматическая битва\n";
    cout << "2. Интерактивный режим\n";
    cout << "Ваш выбор: ";
    cin >> mode;

    if (mode == 1) {
        battle();
    }
    else if (mode == 2) {
        interactiveMode();
    }
    else {
        cout << "Неверный выбор, запускаю автоматическую битву.\n";
        battle();
    }

    return 0;
}