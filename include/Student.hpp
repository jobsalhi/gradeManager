#pragma once
#include "User.hpp"
#include <unordered_map>
#include <string>

class Student : public User {
public:
    Student(const std::string& dbPath);
    std::unordered_map<std::string, int> getGrades(int studentId) const;
    double calculateAverage(int studentId) const;
};