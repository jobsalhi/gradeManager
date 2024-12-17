#include "Professor.hpp"

Professor::Professor(const std::string& dbPath) : Student(dbPath) {}

void Professor::addStudent(int studentId, const std::string& studentName) {
    nlohmann::json newStudent = {{"id", studentId}, {"name", studentName}, {"grades", {}}};
    usersData["students"].push_back(newStudent);
    saveUsers();
}

void Professor::modifyGrades(int studentId, const std::vector<int>& grades) {
    for (auto& student : usersData["students"]) {
        if (student["id"] == studentId) {
            student["grades"] = grades;
            break;
        }
    }
    saveUsers();
}