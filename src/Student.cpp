#include "../include/Student.hpp"

Student::Student(const std::string& name) : name(name) {}


double Student::calculateAverage() const {
    if (grades.empty()) return 0.0;
    int sum = 0;
    for (int grade : grades) sum += grade;
    return static_cast<double>(sum) / grades.size();
}

const std::vector<int>& Student::getGrades() const {
    return grades;
}
