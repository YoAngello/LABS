#pragma once

#include "Human.h"
#include <vector>
#include <string>

class Student : public Human {
private:
    std::vector<int> scores;   // Вектор оценок студента

public:
    // Конструктор по умолчанию: вызывает конструктор Human по умолчанию и инициализирует пустой вектор оценок
    Student();

    // Конструктор с параметрами: имя, фамилия, отчество, вектор оценок
    Student(const std::string& firstName, const std::string& lastName,
        const std::string& patronymic, const std::vector<int>& scores);

    // Деструктор
    ~Student() {}

    // Добавляет одну оценку в вектор (принимает значение от 2 до 5)
    void addScore(int score);

    // Вычисляет и возвращает среднее арифметическое всех оценок
    double getAverageScore() const;

    // Возвращает строку вида "<Фамилия><Инициалы>: <Средний балл>", например "Ivanov I.I.: 3.75"
    std::string getShortStudentInfo() const;

    // Возвращает строку "<Фамилия><Имя><Отчество>: <Все оценки> - <Средний балл>"
    std::string getFullStudentInfo() const;

    // Возвращает количество оценок у студента (для поиска студента с наибольшим количеством оценок)
    size_t getScoresCount() const;

    // Возвращает константную ссылку на вектор оценок (для сохранения в файл)
    const std::vector<int>& getScores() const;
};