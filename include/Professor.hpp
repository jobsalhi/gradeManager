#pragma once
#include "Student.hpp"

class Professor : public Student {
public:
    Professor(const std::string& dbPath);
    void addStudent(int studentId, const std::string& studentName);
    void modifyGrades(int studentId, const std::vector<int>& grades);
};