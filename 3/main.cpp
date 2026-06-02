#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> words;
    string word;

    // Читаем все слова до конца ввода
    while (cin >> word) {
        words.push_back(word);
    }

    if (words.empty()) {
        return 0;
    }

    // Буквы первого слова
    set<char> commonLetters;
    for (char c : words[0]) {
        commonLetters.insert(c);
    }

    // Пересекаем с буквами каждого следующего слова
    for (size_t i = 1; i < words.size(); ++i) {
        set<char> currentLetters;
        for (char c : words[i]) {
            currentLetters.insert(c);
        }

        // Оставляем только те буквы, которые есть в текущем слове
        set<char> intersection;
        for (char c : commonLetters) {
            if (currentLetters.find(c) != currentLetters.end()) {
                intersection.insert(c);
            }
        }
        commonLetters = intersection;

        // Если общих букв не осталось, можно выйти
        if (commonLetters.empty()) {
            break;
        }
    }

    // Выводим общие буквы в алфавитном порядке
    for (char c : commonLetters) {
        cout << c;
    }
    cout << endl;

    return 0;
}