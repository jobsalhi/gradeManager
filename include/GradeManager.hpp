#pragma once
#include <unordered_map>
#include <vector>
#include <string>

class GradeManager {
public:
    void setGradesData(const std::unordered_map<int, std::vector<int>>& data);
    void addStudent(int id, const std::string& name);
    void addGrade(int id, int grade);
    std::vector<int> getGrades(int id) const;
    double calculateAverage(int id) const;

private:
    std::unordered_map<int, std::vector<int>> gradesData;
    std::unordered_map<int, std::string> studentNames;
};