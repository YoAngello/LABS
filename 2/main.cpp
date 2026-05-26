#include "Animal.h"
#include "Fish.h"
#include "Bird.h"
#include "FlyingBird.h"

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int main() {
    cout << "Testing Animal class hierarchy" << endl;

    // 1. Fish
    cout << "1. Fish object " << endl;
    Fish fish("Nemo");
    fish.breathe();
    fish.eat();
    fish.swim();
    cout << endl;

    // 2. Bird
    cout << "2. Bird object " << endl;
    Bird bird("Kesha");
    bird.breathe();
    bird.eat();
    bird.lay_eggs();
    cout << endl;

    // 3. Flying bird
    cout << "3. FlyingBird object " << endl;
    FlyingBird flyingBird("Eagle");
    flyingBird.breathe();
    flyingBird.eat();
    flyingBird.lay_eggs();
    flyingBird.fly();
    cout << endl;
    
    
    
    vector<Animal*> animals;

    Fish* fish2 = new Fish("Dory");
    Bird* bird2 = new Bird("Gosha");
    FlyingBird* flyingBird2 = new FlyingBird("Falcon");

    animals.push_back(fish2);
    animals.push_back(bird2);
    animals.push_back(flyingBird2);

    for (size_t i = 0; i < animals.size(); i++) {
        cout << "Object " << i + 1 << ":" << endl;
        animals[i]->breathe();
        animals[i]->eat();
        cout << endl;
    }