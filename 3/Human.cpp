#include "Human.h"

// Конструктор по умолчанию: устанавливает "Unknown" для всех полей
Human::Human() : firstName("Unknown"), lastName("Unknown"), patronymic("Unknown") {}

// Конструктор с параметрами: инициализирует поля переданными значениями
Human::Human(const std::string& firstName, const std::string& lastName, const std::string& patronymic)
    : firstName(firstName), lastName(lastName), patronymic(patronymic) {
}

// Возвращает фамилию с инициалами 
std::string Human::getSurnameAndInitials() const {
    std::string result = lastName + " ";
    if (!firstName.empty()) {
        result += firstName.substr(0, 1) + ".";
    }
    if (!patronymic.empty()) {
        result += patronymic.substr(0, 1) + ".";
    }
    return result;
}

// Возвращает полное ФИО 
std::string Human::getFullName() const {
    return lastName + " " + firstName + " " + patronymic;
}

// Геттер для имени
std::string Human::getFirstName() const { return firstName; }

// Геттер для фамилии
std::string Human::getLastName() const { return lastName; }

// Геттер для отчества
std::string Human::getPatronymic() const { return patronymic; }