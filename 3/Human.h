#pragma once

#include <string>

class Human {
private:
    std::string firstName;   // Имя
    std::string lastName;    // Фамилия
    std::string patronymic;  // Отчество

public:
    // Конструктор по умолчанию (все поля = "Неизвестно")
    Human();

    // Конструктор с параметрами (имя, фамилия, отчество)
    Human(const std::string& firstName, const std::string& lastName, const std::string& patronymic);

    // Виртуальный деструктор
    virtual ~Human() {}

    // Возвращает строку вида "<Фамилия> <Инициалы>", например "Ivanov I.I."
    std::string getSurnameAndInitials() const;

    // Возвращает строку вида "<Фамилия> <Имя> <Отчество>", например "Ivanov Ivan Ivanovich"
    std::string getFullName() const;

    // Геттер для имени (для наследников)
    std::string getFirstName() const;

    // Геттер для фамилии (для наследников)
    std::string getLastName() const;

    // Геттер для отчества (для наследников)
    std::string getPatronymic() const;
};