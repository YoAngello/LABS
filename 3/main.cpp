#include "Student.h"
#include "Teacher.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// Сохраняет список студентов в файл
void saveStudentsToFile(const vector<Student>& students, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: cannot open file " << filename << " for writing" << endl;
        return;
    }

    for (const auto& s : students) {
        file << s.getFirstName() << "|"
            << s.getLastName() << "|"
            << s.getPatronymic() << "|";

        const auto& scores = s.getScores();
        file << scores.size();
        for (int score : scores) {
            file << "|" << score;
        }
        file << endl;
    }

    file.close();
    cout << "Saved " << students.size() << " students to " << filename << endl;
}

// Загружает список студентов из файла
vector<Student> loadStudentsFromFile(const string& filename) {
    vector<Student> students;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: cannot open file " << filename << " for reading" << endl;
        return students;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string firstName, lastName, patronymic, token;
        vector<int> scores;

        getline(ss, firstName, '|');
        getline(ss, lastName, '|');
        getline(ss, patronymic, '|');
        getline(ss, token, '|');

        int scoreCount = stoi(token);
        for (int i = 0; i < scoreCount; i++) {
            getline(ss, token, '|');
            scores.push_back(stoi(token));
        }

        students.emplace_back(firstName, lastName, patronymic, scores);
    }

    file.close();
    cout << "Loaded " << students.size() << " students from " << filename << endl;
    return students;
}

// Сохраняет список преподавателей в файл
void saveTeachersToFile(const vector<Teacher>& teachers, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: cannot open file " << filename << " for writing" << endl;
        return;
    }

    for (const auto& t : teachers) {
        file << t.getFirstName() << "|"
            << t.getLastName() << "|"
            << t.getPatronymic() << "|"
            << static_cast<int>(t.getPosition()) << "|";

        const auto& subjects = t.getSubjects();
        file << subjects.size();
        for (const auto& subj : subjects) {
            file << "|" << subj;
        }
        file << endl;
    }

    file.close();
    cout << "Saved " << teachers.size() << " teachers to " << filename << endl;
}

// Загружает список преподавателей из файла
vector<Teacher> loadTeachersFromFile(const string& filename) {
    vector<Teacher> teachers;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: cannot open file " << filename << " for reading" << endl;
        return teachers;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string firstName, lastName, patronymic, token;
        vector<string> subjects;

        getline(ss, firstName, '|');
        getline(ss, lastName, '|');
        getline(ss, patronymic, '|');
        getline(ss, token, '|');

        Position pos = static_cast<Position>(stoi(token));
        getline(ss, token, '|');

        int subjectCount = stoi(token);
        for (int i = 0; i < subjectCount; i++) {
            getline(ss, token, '|');
            subjects.push_back(token);
        }

        teachers.emplace_back(firstName, lastName, patronymic, pos, subjects);
    }

    file.close();
    cout << "Loaded " << teachers.size() << " teachers from " << filename << endl;
    return teachers;
}

// Создаёт тестовые данные (10 студентов и 10 преподавателей)
void createTestData(vector<Student>& students, vector<Teacher>& teachers) {
    // Студенты
    students.emplace_back("Ivan", "Ivanov", "Ivanovich", vector<int>{5, 5, 4, 5, 4});
    students.emplace_back("Petr", "Petrov", "Petrovich", vector<int>{3, 4, 3, 4, 3});
    students.emplace_back("Sidor", "Sidorov", "Sidorovich", vector<int>{2, 3, 2, 3, 2});
    students.emplace_back("Anna", "Smirnova", "Alexeevna", vector<int>{5, 5, 5, 5, 5, 5});
    students.emplace_back("Olga", "Kuznetsova", "Dmitrievna", vector<int>{4, 4, 4, 4});
    students.emplace_back("Dmitry", "Popov", "Sergeevich", vector<int>{3, 3, 4, 3, 3, 4});
    students.emplace_back("Elena", "Vasilyeva", "Andreevna", vector<int>{5, 4, 5, 4, 5});
    students.emplace_back("Alexey", "Morozov", "Vladimirovich", vector<int>{2, 2, 3, 2});
    students.emplace_back("Maria", "Novikova", "Igorevna", vector<int>{4, 5, 4, 5, 4, 5, 4});
    students.emplace_back("Nikolay", "Volkov", "Pavlovich", vector<int>{3, 3, 3, 3, 3});

    // Преподаватели
    teachers.emplace_back("Sergey", "Mikhailov", "Alexandrovich", Position::Assistant,
        vector<string>{"Mathematics", "Physics"});
    teachers.emplace_back("Natalia", "Fedorova", "Vladimirovna", Position::SeniorLecturer,
        vector<string>{"Programming", "Algorithms"});
    teachers.emplace_back("Andrey", "Sokolov", "Nikolaevich", Position::AssociateProfessor,
        vector<string>{"Computer Science", "Databases", "Operating Systems"});
    teachers.emplace_back("Tatyana", "Lebedeva", "Borisovna", Position::Professor,
        vector<string>{"Artificial Intelligence", "Machine Learning", "Data Mining",
        "Neural Networks", "Deep Learning"});
    teachers.emplace_back("Vladimir", "Kozlov", "Ivanovich", Position::Professor,
        vector<string>{"Computer Science", "Programming", "Data Structures"});
    teachers.emplace_back("Irina", "Novikova", "Petrovna", Position::AssociateProfessor,
        vector<string>{"Computer Science", "Web Technologies", "UI/UX Design"});
    teachers.emplace_back("Pavel", "Zaitsev", "Dmitrievich", Position::SeniorLecturer,
        vector<string>{"Physics", "Chemistry"});
    teachers.emplace_back("Ekaterina", "Solovyova", "Alexandrovna", Position::Professor,
        vector<string>{"Computer Science", "Information Systems", "Data Analysis"});
    teachers.emplace_back("Mikhail", "Belyaev", "Sergeevich", Position::AssociateProfessor,
        vector<string>{"Computer Science", "Network Technologies", "Cybersecurity"});
    teachers.emplace_back("Anna", "Titova", "Viktorovna", Position::Assistant,
        vector<string>{"Computer Science", "Python Programming"});
}

int main() {
    cout << "========================================" << endl;
    cout << "Student and Teacher Management System" << endl;
    cout << "========================================" << endl << endl;

    vector<Student> students;
    vector<Teacher> teachers;

    // Создание тестовых данных
    createTestData(students, teachers);

    // Демонстрация сохранения и загрузки
    cout << "--- FILE SAVE/LOAD DEMONSTRATION ---" << endl;
    saveStudentsToFile(students, "students.txt");
    saveTeachersToFile(teachers, "teachers.txt");

    vector<Student> loadedStudents = loadStudentsFromFile("students.txt");
    vector<Teacher> loadedTeachers = loadTeachersFromFile("teachers.txt");
    cout << endl;

    // Используем загруженные данные для отчётов
    students = loadedStudents;
    teachers = loadedTeachers;

    cout << "--- REPORTS ---" << endl << endl;

    // 1) Студенты со средним баллом больше 4
    cout << "1) Students with average score > 4:" << endl;
    for (const auto& s : students) {
        if (s.getAverageScore() > 4.0) {
            cout << "   " << s.getShortStudentInfo() << endl;
        }
    }
    cout << endl;

    // 2) Студенты со средним баллом меньше 3
    cout << "2) Students with average score < 3:" << endl;
    for (const auto& s : students) {
        if (s.getAverageScore() < 3.0) {
            cout << "   " << s.getShortStudentInfo() << endl;
        }
    }
    cout << endl;

    // 3) Студент с наибольшим количеством оценок
    cout << "3) Student with most scores:" << endl;
    auto maxScoresStudent = max_element(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.getScoresCount() < b.getScoresCount();
        });
    if (maxScoresStudent != students.end()) {
        cout << "   " << maxScoresStudent->getFullStudentInfo() << endl;
    }
    cout << endl;

    // 4) Все доценты (краткая информация)
    cout << "4) All associate professors:" << endl;
    for (const auto& t : teachers) {
        if (t.getPosition() == Position::AssociateProfessor) {
            cout << "   " << t.getShortTeacherInfo() << endl;
        }
    }
    cout << endl;

    // 5) Профессор с наибольшим количеством предметов
    cout << "5) Professor with most subjects:" << endl;
    size_t maxSubjects = 0;
    const Teacher* profWithMost = nullptr;

    for (const auto& t : teachers) {
        if (t.getPosition() == Position::Professor && t.getSubjectsCount() > maxSubjects) {
            maxSubjects = t.getSubjectsCount();
            profWithMost = &t;
        }
    }

    if (profWithMost) {
        cout << "   " << profWithMost->getFullTeacherInfo() << endl;
    }
    cout << endl;

    // 6) Преподаватели, которые ведут Computer Science (информатику)
    cout << "6) Teachers who teach Computer Science:" << endl;
    for (const auto& t : teachers) {
        const auto& subjects = t.getSubjects();
        if (find(subjects.begin(), subjects.end(), "Computer Science") != subjects.end()) {
            cout << "   " << t.getFullTeacherInfo() << endl;
        }
    }

    cout << endl;
    cout << "========================================" << endl;
    cout << "Program completed successfully" << endl;
    cout << "========================================" << endl;

    return 0;
}