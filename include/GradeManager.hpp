#pragma once
#include <unordered_map>
#include <vector>
#include <string>

class GradeManager {
public:
    void setGradesData(const std::unordered_map<int, std::unordered_map<std::string, int>>& data);
    void addStudent(int id, const std::string& name);
    void addGrade(int id, const std::string& subject, int grade);
    std::unordered_map<std::string, int> getGrades(int id) const;
    double calculateAverage(int id) const;

private:
    std::unordered_map<int, std::unordered_map<std::string, int>> gradesData;
    std::unordered_map<int, std::string> studentNames;
};