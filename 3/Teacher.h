#pragma once

#include "Human.h"
#include <vector>
#include <string>

// Перечисление должностей
enum class Position {
    Assistant,           // Ассистент
    SeniorLecturer,      // Старший преподаватель
    AssociateProfessor,  // Доцент
    Professor,           // Профессор
    Unknown              // Неизвестно
};

class Teacher : public Human {
private:
    Position position;                      // Должность
    std::vector<std::string> subjects;      // Список преподаваемых предметов

public:
    // Конструктор по умолчанию: должность = Unknown, пустой вектор предметов
    Teacher();

    // Конструктор с параметрами: имя, фамилия, отчество, должность, вектор предметов
    Teacher(const std::string& firstName, const std::string& lastName,
        const std::string& patronymic, Position position,
        const std::vector<std::string>& subjects);

    // Деструктор
    ~Teacher() {}

    // Добавляет один предмет в список
    void addSubject(const std::string& subject);

    // Возвращает краткую информацию: "<Фамилия><Инициалы><Должность>: <Количество предметов>"
    std::string getShortTeacherInfo() const;

    // Возвращает полную информацию: "<ФИО><Должность>: <Все предметы через запятую>"
    std::string getFullTeacherInfo() const;

    // Геттер для должности (для фильтрации)
    Position getPosition() const;

    // Геттер для количества предметов (для поиска)
    size_t getSubjectsCount() const;

    // Геттер для вектора предметов (для поиска по предмету и сохранения)
    const std::vector<std::string>& getSubjects() const;
};

// Вспомогательная функция: преобразует enum Position в строку
std::string positionToString(Position pos);