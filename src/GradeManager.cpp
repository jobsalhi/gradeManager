#include "../include/GradeManager.hpp"
#include <iostream>
#include <numeric>

// Add a student
void GradeManager::addStudent(const std::string& name) {
    if (studentGrades.find(name) == studentGrades.end()) {
        studentGrades[name] = {};
    } else {
        std::cout << "Student already exists.\n";
    }
}

// Add a grade for a student
void GradeManager::addGrade(const std::string& name, int grade) {
    if (studentGrades.find(name) != studentGrades.end()) {
        studentGrades[name].push_back(grade);
    } else {
        std::cout << "Student not found.\n";
    }
}

// Get grades of a student
std::vector<int> GradeManager::getGrades(const std::string& name) const {
    auto it = studentGrades.find(name);
    if (it != studentGrades.end()) {
        return it->second;
    } else {
        return {};
    }
}

// Calculate average of grades for a student
double GradeManager::calculateAverage(const std::string& name) const {
    auto it = studentGrades.find(name);
    if (it != studentGrades.end() && !it->second.empty()) {
        return static_cast<double>(std::accumulate(it->second.begin(), it->second.end(), 0)) / it->second.size();
    } else {
        return 0.0;
    }
}
