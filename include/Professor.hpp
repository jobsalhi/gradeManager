#pragma once
#include "Student.hpp"
#include <unordered_map>

class Professor : public Student {
public:
    Professor(const std::string& dbPath);
    void modifyGrade(int studentId, const std::string &subject, int grade);
    void addGrade(int studentId, const std::string& subject, int grade);
    void displayStudents();
    void deleteStudent(int studentId);
};