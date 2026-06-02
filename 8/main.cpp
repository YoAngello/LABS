#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <iomanip>
#include <numeric>

using namespace std;

// Функция для вывода вектора на экран
void printVector(const vector<int>& v, const string& title = "") {
    if (!title.empty()) {
        cout << title << ": ";
    }

    if (v.empty()) {
        cout << "пусто" << endl;
        return;
    }

    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) {
            cout << ", ";
        }
    }
    cout << endl;
}

// Функция для чтения данных из файла
vector<int> readDataFromFile(const string& filename) {
    vector<int> data;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть файл " << filename << endl;
        return data;
    }

    int number;
    while (file >> number) {
        data.push_back(number);
    }

    file.close();
    cout << "Прочитано " << data.size() << " чисел из файла." << endl;
    return data;
}

// Функция для ввода чисел с клавиатуры (альтернативный вариант)
vector<int> readDataFromConsole() {
    vector<int> data;
    cout << "Введите числа (для завершения введите любой нечисловой символ):" << endl;

    int number;
    while (cin >> number) {
        data.push_back(number);
    }

    cin.clear();
    return data;
}

int main() {
    cout << "=== ОБРАБОТКА НАБОРА ЦЕЛЫХ ЧИСЕЛ ===" << endl;
    cout << endl;

    // Чтение данных из файла
    string filename = "data.txt";
    vector<int> original = readDataFromFile(filename);

    if (original.empty()) {
        cout << "Файл пуст или не найден. Введите данные вручную:" << endl;
        original = readDataFromConsole();
    }

    if (original.empty()) {
        cout << "Нет данных для обработки!" << endl;
        return 1;
    }

    cout << endl;
    printVector(original, "Исходный набор данных");
    cout << endl;

    // ========== Пункт a ==========
    cout << "=== ПУНКТ А ===" << endl;
    int n;
    cout << "Введите число для поиска: ";
    cin >> n;

    // Подсчёт количества вхождений
    int count = count(original.begin(), original.end(), n);
    cout << "Число " << n << " встречается " << count << " раз(а)" << endl;

    // Поиск всех позиций
    if (count > 0) {
        vector<int> positions;
        auto it = original.begin();
        while ((it = find(it, original.end(), n)) != original.end()) {
            positions.push_back(distance(original.begin(), it));
            ++it;
        }

        cout << "Позиции числа " << n << " (индексация с 0): ";
        for (size_t i = 0; i < positions.size(); ++i) {
            cout << positions[i];
            if (i + 1 < positions.size()) cout << ", ";
        }
        cout << endl;
    }
    cout << endl;

    // ========== Пункт b ==========
    cout << "=== ПУНКТ Б ===" << endl;

    // Подсчёт чётных и нечётных элементов
    int evenCount = count_if(original.begin(), original.end(),
        [](int x) { return x % 2 == 0; });
    int oddCount = original.size() - evenCount;

    cout << "Количество чётных элементов: " << evenCount << endl;
    cout << "Количество нечётных элементов: " << oddCount << endl;

    // Вывод номеров чётных элементов
    if (evenCount > 0) {
        vector<int> evenPositions;
        for (size_t i = 0; i < original.size(); ++i) {
            if (original[i] % 2 == 0) {
                evenPositions.push_back(i);
            }
        }

        cout << "Номера (индексы) чётных элементов: ";
        for (size_t i = 0; i < evenPositions.size(); ++i) {
            cout << evenPositions[i];
            if (i + 1 < evenPositions.size()) cout << ", ";
        }
        cout << endl;
    }

    // Суммы
    if (evenCount > oddCount) {
        int sumEven = 0;
        for (int x : original) {
            if (x % 2 == 0) {
                sumEven += x;
            }
        }
        cout << "Чётных больше, сумма чётных элементов: " << sumEven << endl;
    }
    else {
        int sumAll = accumulate(original.begin(), original.end(), 0);
        cout << "Нечётных больше или поровну, сумма всех элементов: " << sumAll << endl;
    }
    cout << endl;

    // ========== Пункт c ==========
    cout << "=== ПУНКТ В ===" << endl;

    vector<int> sorted = original;
    sort(sorted.begin(), sorted.end());

    printVector(original, "Исходный набор");
    printVector(sorted, "Отсортированный набор (по возрастанию)");

    // Сортировка по убыванию
    vector<int> descending = original;
    sort(descending.begin(), descending.end(), greater<int>());
    printVector(descending, "Отсортированный набор (по убыванию)");
    cout << endl;

    // ========== Пункт d ==========
    cout << "=== ПУНКТ Г ===" << endl;

    vector<int> swapped = original;
    if (!swapped.empty()) {
        swap(swapped.front(), swapped.back());
        printVector(swapped, "После перестановки первого и последнего элемента");
    }
    else {
        cout << "Вектор пуст, перестановка невозможна" << endl;
    }
    cout << endl;

    // Дополнительные демонстрации алгоритмов
    cout << "=== ДОПОЛНИТЕЛЬНАЯ ИНФОРМАЦИЯ ===" << endl;

    // Минимальный и максимальный элементы
    if (!original.empty()) {
        int minElem = *min_element(original.begin(), original.end());
        int maxElem = *max_element(original.begin(), original.end());
        cout << "Минимальный элемент: " << minElem << endl;
        cout << "Максимальный элемент: " << maxElem << endl;

        // Первый чётный элемент
        auto firstEven = find_if(original.begin(), original.end(),
            [](int x) { return x % 2 == 0; });
        if (firstEven != original.end()) {
            cout << "Первый чётный элемент: " << *firstEven
                << " (индекс " << distance(original.begin(), firstEven) << ")" << endl;
        }
        else {
            cout << "Чётных элементов нет" << endl;
        }
    }

    return 0;
}