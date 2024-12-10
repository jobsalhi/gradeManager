#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>

class Student {
private:
    std::string name;
    std::vector<int> grades;

public:
    Student(const std::string& name);
    // void addGrade(int grade);
    double calculateAverage() const;
    const std::vector<int>& getGrades() const;
};

#endif // STUDENT_HPP
