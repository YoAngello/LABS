#include <iostream>
#include <string>
#include "matrix.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "=== Демонстрация для типа int ===" << endl;
    try {
        Matrix<int> A, B;

        cout << "Введите матрицу A (в формате: rows cols затем элементы):" << endl;
        cin >> A;
        cout << "Введите матрицу B (в формате: rows cols затем элементы):" << endl;
        cin >> B;

        cout << "Матрица A:" << endl << A;
        cout << "Матрица B:" << endl << B;

        cout << "A + B:" << endl << (A + B);

        cout << "A * B:" << endl << (A * B);

        // Проверка методов Get/Set
        cout << "Элемент A[0][0] = " << A.Get(0, 0) << endl;
        A.Set(0, 0, 100);
        cout << "После Set(0,0,100) A[0][0] = " << A.Get(0, 0) << endl;
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    cout << "\n=== Демонстрация для типа string ===" << endl;
    try {
        Matrix<string> C, D;

        cout << "Введите матрицу C (размер и строки):" << endl;
        cin >> C;
        cout << "Введите матрицу D (размер и строки):" << endl;
        cin >> D;

        cout << "Матрица C:" << endl << C;
        cout << "Матрица D:" << endl << D;

        cout << "C + D (конкатенация строк):" << endl << (C + D);

        // Умножение для строк определено как конкатенация с дублированием? Нет, логики нет — для строк * не имеет смысла, поэтому вызовем ошибку.
        // Чтобы показать обработку ошибки, закомментируем, иначе компилятор не поймёт * для строк.
        // cout << "C * D (не имеет смысла для строк, выбросит исключение)" << endl << (C * D);
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}