#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<int> seenNumbers;  // Хеш-таблица для быстрого поиска
    int number;

    while (cin >> number) {
        if (seenNumbers.find(number) != seenNumbers.end()) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
            seenNumbers.insert(number);
        }
    }

    return 0;
}