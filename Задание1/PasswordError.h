#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

// Базовый класс для всех ошибок пароля
class PasswordError : public std::runtime_error {
public:
    explicit PasswordError(const std::string& message) : std::runtime_error(message) {}
};

// Ошибка длины пароля
class LengthError : public PasswordError {
public:
    explicit LengthError() : PasswordError("Ошибка: длина пароля меньше 9 символов") {}
};

// Ошибка регистра
class RegisterError : public PasswordError {
public:
    explicit RegisterError() : PasswordError("Ошибка: все символы пароля одного регистра") {}
};

// Ошибка отсутствия цифр
class DigitError : public PasswordError {
public:
    explicit DigitError() : PasswordError("Ошибка: в пароле нет ни одной цифры") {}
};

// Ошибка запрещённых символов
class ForbiddenLetterError : public PasswordError {
private:
    char forbiddenChar;
public:
    explicit ForbiddenLetterError(char c)
        : PasswordError("Ошибка: запрещённый символ '" + std::string(1, c) +
            "' (можно перепутать с другими)"), forbiddenChar(c) {
    }

    char getForbiddenChar() const { return forbiddenChar; }
};
