#include "Student.h"
#include <numeric>
#include <sstream>
#include <iomanip>

// Конструктор по умолчанию: вызывает конструктор Human по умолчанию
Student::Student() : Human() {}

// Конструктор с параметрами: вызывает конструктор Human и инициализирует вектор оценок
Student::Student(const std::string& firstName, const std::string& lastName,
    const std::string& patronymic, const std::vector<int>& scores)
    : Human(firstName, lastName, patronymic), scores(scores) {
}

// Добавляет одну оценку (проверяет, что оценка в диапазоне 2-5)
void Student::addScore(int score) {
    if (score >= 2 && score <= 5) {
        scores.push_back(score);
    }
}

// Вычисляет среднее арифметическое оценок. Если оценок нет, возвращает 0.0
double Student::getAverageScore() const {
    if (scores.empty()) return 0.0;
    double sum = std::accumulate(scores.begin(), scores.end(), 0.0);
    return sum / scores.size();
}

// Возвращает краткую информацию: фамилия с инициалами и средний балл
std::string Student::getShortStudentInfo() const {
    std::ostringstream oss;
    oss << getSurnameAndInitials() << ": " << std::fixed << std::setprecision(2) << getAverageScore();
    return oss.str();
}

// Возвращает полную информацию: ФИО, все оценки через пробел, средний балл
std::string Student::getFullStudentInfo() const {
    std::ostringstream oss;
    oss << getFullName() << ": ";
    for (size_t i = 0; i < scores.size(); i++) {
        oss << scores[i];
        if (i < scores.size() - 1) oss << " ";
    }
    oss << " - " << std::fixed << std::setprecision(2) << getAverageScore();
    return oss.str();
}

// Возвращает количество оценок
size_t Student::getScoresCount() const {
    return scores.size();
}

// Возвращает константную ссылку на вектор оценок
const std::vector<int>& Student::getScores() const {
    return scores;
}