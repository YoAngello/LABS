#include <iostream>
#include "Figures.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"

using namespace std;

void demonstratePolymorphism() {
    cout << "\n=== ÏÎËÈÌÎÐÔÈÇÌ ===\n" << endl;

    Figure* figures[] = {
        new Rectangle(3, 4),
        new Circle(5),
        new Square(6),
        new Triangle(3, 4, 5)
    };

    for (Figure* fig : figures) {
        cout << fig->to_string() << endl;
        cout << "Ïëîùàäü: " << fig->calc_area() << endl;
        cout << "Îáú¸ì öèëèíäðà (h=10): " << calc_cylinder_volume(fig, 10) << endl;
        cout << "------------------------" << endl;
        delete fig;
    }
}

int main() {
    cout << "=== ÑÈÑÒÅÌÀ ÃÅÎÌÅÒÐÈ×ÅÑÊÈÕ ÔÈÃÓÐ ===\n" << endl;

    demonstratePolymorphism();

    cout << "\n=== ÈÍÒÅÐÀÊÒÈÂÍÛÉ ÐÅÆÈÌ ===\n" << endl;
    cout << "1-Êðóã 2-Ïðÿìîóãîëüíèê 3-Êâàäðàò 4-Òðåóãîëüíèê" << endl;
    cout << "Âûáîð: ";

    int choice;
    cin >> choice;

    Figure* figure = nullptr;

    switch (choice) {
    case 1: {
        double r;
        cout << "Ðàäèóñ: ";
        cin >> r;
        figure = new Circle(r);
        break;
    }
    case 2: {
        double w, h;
        cout << "Øèðèíà è âûñîòà: ";
        cin >> w >> h;
        figure = new Rectangle(w, h);
        break;
    }
    case 3: {
        double s;
        cout << "Ñòîðîíà: ";
        cin >> s;
        figure = new Square(s);
        break;
    }
    case 4: {
        double a, b, c;
        cout << "Òðè ñòîðîíû: ";
        cin >> a >> b >> c;
        figure = new Triangle(a, b, c);
        break;
    }
    default:
        cout << "Íåâåðíûé âûáîð. Ñîçäàí ïðÿìîóãîëüíèê 3x4" << endl;
        figure = new Rectangle(3, 4);
        break;
    }

    cout << figure->to_string() << endl;
    cout << "Ïëîùàäü: " << figure->calc_area() << endl;

    double h;
    cout << "Âûñîòà öèëèíäðà: ";
    cin >> h;
    cout << "Îáú¸ì öèëèíäðà: " << calc_cylinder_volume(figure, h) << endl;

    delete figure;
    return 0;
}