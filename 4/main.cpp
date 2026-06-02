#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> wordCount;  // Хранит количество встреч каждого слова
    string word;

    // Читаем слова до конца ввода
    while (cin >> word) {
        // Увеличиваем счётчик и выводим его значение
        wordCount[word]++;
        cout << wordCount[word] << endl;
    }

    return 0;
}