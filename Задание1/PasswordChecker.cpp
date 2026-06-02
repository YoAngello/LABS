#include "PasswordError.h"
#include <string>
#include <cctype>
#include <iostream>

using namespace std;

// Проверка на запрещённые символы
bool isForbidden(char c) {
    string forbidden = "lI1oO0";
    return forbidden.find(c) != string::npos;
}

// Функция запроса и проверки пароля
string get_password() {
    string password;

    cout << "Введите пароль: ";
    getline(cin, password);

    // 1. Проверка длины
    if (password.length() < 9) {
        throw LengthError();
    }

    // 2. Проверка регистра
    bool hasUpper = false;
    bool hasLower = false;

    for (char c : password) {
        if (isupper(c)) hasUpper = true;
        if (islower(c)) hasLower = true;
    }

    if (!hasUpper || !hasLower) {
        throw RegisterError();
    }

    // 3. Проверка наличия цифр
    bool hasDigit = false;
    for (char c : password) {
        if (isdigit(c)) {
            hasDigit = true;
            break;
        }
    }

    if (!hasDigit) {
        throw DigitError();
    }

    // 4. Проверка запрещённых символов
    for (char c : password) {
        if (isForbidden(c)) {
            throw ForbiddenLetterError(c);
        }
    }

    return password;
}