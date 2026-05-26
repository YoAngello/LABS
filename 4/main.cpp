#include "Summator.h"
#include "SquareSummator.h"
#include "CubeSummator.h"

#include <iostream>
#include <memory>
#include <vector>
#include <cmath>

using namespace std;

// Функция для проверки корректности суммы Σ i по формуле N(N+1)/2
bool checkSumFormula(int N, long long result) {
    long long expected = (long long)N * (N + 1) / 2;
    return result == expected;
}

// Функция для проверки корректности суммы Σ i² по формуле N(N+1)(2N+1)/6
bool checkSquareFormula(int N, long long result) {
    long long expected = (long long)N * (N + 1) * (2 * N + 1) / 6;
    return result == expected;
}

// Функция для проверки корректности суммы Σ i³ по формуле [N(N+1)/2]²
bool checkCubeFormula(int N, long long result) {
    long long sum = (long long)N * (N + 1) / 2;
    long long expected = sum * sum;
    return result == expected;
}

// Функция для ввода положительного целого числа
int inputPositiveInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value <= 0) {
            cout << "Error: please enter a positive integer!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else {
            cin.ignore(10000, '\n');
            return value;
        }
    }
}

int main() {
    cout << "========================================" << endl;
    cout << "Summator Classes Test" << endl;
    cout << "========================================" << endl << endl;

    // Ввод числа N
    int N = inputPositiveInt("Enter a natural number N: ");
    cout << endl;

    // ========== РАННЕЕ СВЯЗЫВАНИЕ (объекты на стеке) ==========
    cout << "--- EARLY BINDING (stack objects) ---" << endl << endl;

    // 1. Обычный сумматор (сумма чисел от 1 до N)
    Summator summator;
    long long sumResult = summator.sum(N);
    cout << "1. Summator (sum of 1.." << N << "): " << sumResult << endl;

    // Проверка по формуле
    if (checkSumFormula(N, sumResult)) {
        cout << "   Formula check: N(N+1)/2 = " << (long long)N * (N + 1) / 2 << " - CORRECT" << endl;
    }
    else {
        cout << "   Formula check: FAILED!" << endl;
    }
    cout << endl;

    // 2. Квадратный сумматор (сумма квадратов)
    SquareSummator squareSummator;
    long long squareResult = squareSummator.sum(N);
    cout << "2. SquareSummator (sum of squares 1².." << N << "²): " << squareResult << endl;

    // Проверка по формуле
    if (checkSquareFormula(N, squareResult)) {
        cout << "   Formula check: N(N+1)(2N+1)/6 = "
            << (long long)N * (N + 1) * (2 * N + 1) / 6 << " - CORRECT" << endl;
    }
    else {
        cout << "   Formula check: FAILED!" << endl;
    }
    cout << endl;

    // 3. Кубический сумматор (сумма кубов)
    CubeSummator cubeSummator;
    long long cubeResult = cubeSummator.sum(N);
    cout << "3. CubeSummator (sum of cubes 1³.." << N << "³): " << cubeResult << endl;

    // Проверка по формуле
    if (checkCubeFormula(N, cubeResult)) {
        long long sum = (long long)N * (N + 1) / 2;
        cout << "   Formula check: [N(N+1)/2]² = " << sum * sum << " - CORRECT" << endl;
    }
    else {
        cout << "   Formula check: FAILED!" << endl;
    }
    cout << endl;

    // ========== ПОЗДНЕЕ СВЯЗЫВАНИЕ (через указатели на базовый класс) ==========
    cout << "--- LATE BINDING (via Summator* pointers) ---" << endl << endl;

    // Массив указателей на базовый класс
    vector<Summator*> summators;

    Summator* s1 = new Summator();
    SquareSummator* s2 = new SquareSummator();
    CubeSummator* s3 = new CubeSummator();

    summators.push_back(s1);
    summators.push_back(s2);
    summators.push_back(s3);

    const char* names[] = { "Summator", "SquareSummator", "CubeSummator" };

    for (size_t i = 0; i < summators.size(); i++) {
        long long result = summators[i]->sum(N);
        cout << names[i] << " sum(1.." << N << "): " << result << endl;
    }

    cout << endl;

    // ========== ПОЗДНЕЕ СВЯЗЫВАНИЕ (через умные указатели) ==========
    cout << "--- LATE BINDING (unique_ptr<Summator>) ---" << endl << endl;

    vector<unique_ptr<Summator>> smartSummators;

    smartSummators.push_back(make_unique<Summator>());
    smartSummators.push_back(make_unique<SquareSummator>());
    smartSummators.push_back(make_unique<CubeSummator>());

    for (size_t i = 0; i < smartSummators.size(); i++) {
        long long result = smartSummators[i]->sum(N);
        cout << names[i] << " sum(1.." << N << "): " << result << endl;
    }

    cout << endl;

    // ========== ДЕМОНСТРАЦИЯ РАБОТЫ transform ДЛЯ РАЗНЫХ N ==========
    cout << "--- DEMONSTRATION OF transform() FOR DIFFERENT i ---" << endl << endl;

    Summator baseSummator;
    SquareSummator squareSummator2;
    CubeSummator cubeSummator2;

    cout << "i\t| transform(i) Summator\t| transform(i) SquareSummator\t| transform(i) CubeSummator" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;

    for (int i = 1; i <= min(N, 10); i++) {
        cout << i << "\t| " << baseSummator.transform(i)
            << "\t\t\t| " << squareSummator2.transform(i)
            << "\t\t\t| " << cubeSummator2.transform(i) << endl;
    }

    if (N > 10) {
        cout << "..." << endl;
        cout << N << "\t| " << baseSummator.transform(N)
            << "\t\t\t| " << squareSummator2.transform(N)
            << "\t\t\t| " << cubeSummator2.transform(N) << endl;
    }

    cout << endl;

    // ========== ТАБЛИЦА СУММ ДЛЯ РАЗНЫХ N ==========
    cout << "--- TABLE OF SUMS FOR DIFFERENT N ---" << endl << endl;

    cout << "N\t| Sum 1..N\t| Sum of squares\t| Sum of cubes" << endl;
    cout << "---------------------------------------------------------------" << endl;

    for (int n = 1; n <= min(N, 15); n++) {
        long long sum1 = summator.sum(n);
        long long sum2 = squareSummator.sum(n);
        long long sum3 = cubeSummator.sum(n);

        cout << n << "\t| " << sum1 << "\t\t| " << sum2 << "\t\t\t| " << sum3 << endl;
    }

    if (N > 15) {
        cout << "..." << endl;
        long long sum1 = summator.sum(N);
        long long sum2 = squareSummator.sum(N);
        long long sum3 = cubeSummator.sum(N);
        cout << N << "\t| " << sum1 << "\t\t| " << sum2 << "\t\t\t| " << sum3 << endl;
    }

    cout << endl;
    cout << "========================================" << endl;
    cout << "Program completed successfully" << endl;
    cout << "========================================" << endl;

    // Освобождение памяти
    delete s1;
    delete s2;
    delete s3;

    return 0;
}