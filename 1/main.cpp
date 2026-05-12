#include <iostream>

#include "Figures.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;


int main() {
    Figure* c = nullptr;

    int number;
    cin >> number;

    switch (number) {
        case 1:
            c = new Circle(3);
            break;
        default:
            c = new Rectangle(3, 4);
            break;
    }

    cout << c->to_string() << endl;
    cout << calc_cylinder_volume(c, 5) << endl;

    return 0;
}