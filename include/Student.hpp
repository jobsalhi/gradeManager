#pragma once
#include "User.hpp"
#include <vector>

class Student : public User {
public:
    Student(const std::string& dbPath);
    std::vector<int> getGrades(int studentId) const;
    double calculateAverage(int studentId) const;
};