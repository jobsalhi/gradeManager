#ifndef GRADEMANAGER_HPP
#define GRADEMANAGER_HPP

#include <string>
#include <vector>
#include <map>

class GradeManager {
private:
    std::map<std::string, std::vector<int>> studentGrades; // Map of student names to grades

public:
    void addStudent(const std::string& name);
    void addGrade(const std::string& name, int grade);
    std::vector<int> getGrades(const std::string& name) const;
    double calculateAverage(const std::string& name) const;
};

#endif // GRADEMANAGER_HPP
