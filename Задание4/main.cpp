#include <iostream>
#include "Polynomial.h"
#include "Rational.h"
#include "Complex.h"

using namespace std;

void testInt() {
    cout << "\n=== ÒÅÑÒ ÄËß INT ===\n" << endl;

    vector<int> coeffs1 = { 1, 2, 1 };
    Polynomial<int> p1(coeffs1);

    vector<int> coeffs2 = { 0, 0, 1 };
    Polynomial<int> p2(coeffs2);

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "Ñòåïåíü p1: " << p1.Degree() << endl;
    cout << "Êîýôôèöèåíò ïðè x^1: " << p1[1] << endl;
    cout << "p1(2) = " << p1(2) << endl;

    cout << "p1 + p2 = " << p1 + p2 << endl;
    cout << "p1 - p2 = " << p1 - p2 << endl;
    cout << "p1 * p2 = " << p1 * p2 << endl;

    cout << "p1 + 5 = " << p1 + 5 << endl;
    cout << "10 - p1 = " << 10 - p1 << endl;

    cout << "p1 == p2? " << (p1 == p2 ? "äà" : "íåò") << endl;
}

void testRational() {
    cout << "\n=== ÒÅÑÒ ÄËß RATIONAL ===\n" << endl;

    vector<Rational> coeffs1 = { Rational(1,2), Rational(1,3), Rational(1,6) };
    Polynomial<Rational> p1(coeffs1);

    vector<Rational> coeffs2 = { Rational(1,4), Rational(1,2) };
    Polynomial<Rational> p2(coeffs2);

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "Ñòåïåíü p1: " << p1.Degree() << endl;
    cout << "p1(2) = " << p1(Rational(2)) << endl;

    cout << "p1 + p2 = " << p1 + p2 << endl;
    cout << "p1 - p2 = " << p1 - p2 << endl;
    cout << "p1 * p2 = " << p1 * p2 << endl;
}

void testComplex() {
    cout << "\n=== ÒÅÑÒ ÄËß COMPLEX ===\n" << endl;

    vector<Complex> coeffs1 = { Complex(1,0), Complex(2,0), Complex(1,0) };
    Polynomial<Complex> p1(coeffs1);

    vector<Complex> coeffs2 = { Complex(0,1), Complex(1,0) };
    Polynomial<Complex> p2(coeffs2);

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;

    Complex x(2, 1);
    cout << "p1(" << x << ") = " << p1(x) << endl;

    cout << "p1 + p2 = " << p1 + p2 << endl;
    cout << "p1 - p2 = " << p1 - p2 << endl;
    cout << "p1 * p2 = " << p1 * p2 << endl;
}

void testMore() {
    cout << "\n=== ÄÎÏÎËÍÈÒÅËÜÍÛÅ ÒÅÑÒÛ ===\n" << endl;

    Polynomial<int> zero;
    cout << "Íóëåâîé ìíîãî÷ëåí: " << zero << endl;

    Polynomial<int> constant(42);
    cout << "Êîíñòàíòà: " << constant << endl;

    Polynomial<int> p({ 1, 0, 3, 0, 5 });
    cout << "p = " << p << endl;
    cout << "p[0] = " << p[0] << endl;
    cout << "p[2] = " << p[2] << endl;
    cout << "p[10] = " << p[10] << endl;

    Polynomial<int> q({ 0, 0, 0 });
    cout << "p == 0? " << (p == 0 ? "äà" : "íåò") << endl;
    cout << "q == 0? " << (q == 0 ? "äà" : "íåò") << endl;
}

int main() {
    cout << "=== ØÀÁËÎÍÍÛÉ ÊËÀÑÑ POLYNOMIAL ===" << endl;

    testInt();
    testRational();
    testComplex();
    testMore();

    return 0;
}