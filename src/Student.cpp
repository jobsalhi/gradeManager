#include "Student.hpp"

Student::Student(const std::string& dbPath) : User(dbPath) {}

std::unordered_map<std::string, int> Student::getGrades(int studentId) const {
    for (const auto& student : usersData["students"]) {
        if (student["id"] == studentId) {
            if (!student.contains("grades") || student["grades"].is_null()) {
                return {};
            }
            return student["grades"].get<std::unordered_map<std::string, int>>();
        }
    }
    return {};
}

double Student::calculateAverage(int studentId) const {
    auto grades = getGrades(studentId);
    if (grades.empty()) return 0.0;
    int sum = 0;
    for (const auto& [subject, grade] : grades) {
        sum += grade;
    }
    return static_cast<double>(sum) / grades.size();
}