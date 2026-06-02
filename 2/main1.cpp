#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> seenNumbers;
    int number;

    while (cin >> number) {
        if (seenNumbers.count(number)) {
            // count() возвращает 1, если элемент есть, и 0, если нет
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
            seenNumbers.insert(number);
        }
    }

    return 0;
}