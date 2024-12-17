#include "../include/GradeManager.hpp"
#include <iostream>
#include <numeric>

// Set grades data
void GradeManager::setGradesData(const std::unordered_map<int, std::unordered_map<std::string, int>>& data) {
    gradesData = data;
}

// Add a student
void GradeManager::addStudent(int id, const std::string& name) {
    if (gradesData.find(id) == gradesData.end()) {
        gradesData[id] = {};
        studentNames[id] = name;
    } else {
        std::cout << "Student already exists.\n";
    }
}

// Add a grade for a student
void GradeManager::addGrade(int id, const std::string& subject, int grade) {
    if (gradesData.find(id) != gradesData.end()) {
        gradesData[id][subject] = grade;
    } else {
        std::cout << "Student not found.\n";
    }
}

// Get grades of a student
std::unordered_map<std::string, int> GradeManager::getGrades(int id) const {
    auto it = gradesData.find(id);
    if (it != gradesData.end()) {
        return it->second;
    } else {
        return {};
    }
}

// Calculate average of grades for a student
double GradeManager::calculateAverage(int id) const {
    auto it = gradesData.find(id);
    if (it != gradesData.end() && !it->second.empty()) {
        int sum = 0;
        for (const auto& grade : it->second) {
            sum += grade.second;
        }
        return static_cast<double>(sum) / it->second.size();
    } else {
        return 0.0;
    }
}