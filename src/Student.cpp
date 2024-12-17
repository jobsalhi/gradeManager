#include "Student.hpp"

Student::Student(const std::string& dbPath) : User(dbPath) {}

std::vector<int> Student::getGrades(int studentId) const {
    std::vector<int> grades;
    for (const auto& student : usersData["students"]) {
        if (student["id"] == studentId) {
            for (const auto& grade : student["grades"].items()) {
                grades.push_back(grade.value());
            }
            break;
        }
    }
    return grades;
}

double Student::calculateAverage(int studentId) const {
    std::vector<int> grades = getGrades(studentId);
    if (grades.empty()) return 0.0;
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return static_cast<double>(sum) / grades.size();
}