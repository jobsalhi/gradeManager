#include "Professor.hpp"
#include <iostream>

Professor::Professor(const std::string &dbPath) : Student(dbPath) {}

// void Professor::addStudent(int studentId, const std::string& studentName) {
//     for (auto& student : usersData["students"]) {
//         if (student["id"] == studentId) {
//             std::cout << "Student already exists.\n";
//             return;
//         }
//     }
//     nlohmann::json newStudent = {{"id", studentId}, {"username", studentName}, {"grades", nlohmann::json::object()}};
//     usersData["students"].push_back(newStudent);
//     saveUsers();
// }

void Professor::modifyGrade(int studentId, const std::string &subject, int grade)
{
    for (auto &student : usersData["students"])
    {
        if (student["id"] == studentId)
        {
            student["grades"][subject] = grade;
            saveUsers();
            return;
        }
    }
    std::cout << "Student not found.\n";
}

void Professor::addGrade(int studentId, const std::string &subject, int grade)
{
    for (auto &student : usersData["students"])
    {
        if (student["id"] == studentId)
        {
            student["grades"][subject] = grade;
            saveUsers();
            return;
        }
    }
    std::cout << "Student not found.\n";
}

void Professor::deleteStudent(int studentId)
{
    for (auto it = usersData["students"].begin(); it != usersData["students"].end(); ++it)
    {
        if ((*it)["id"] == studentId)
        {
            usersData["students"].erase(it);
            saveUsers();
            std::cout << "Student deleted successfully.\n";
            return;
        }
    }
    std::cout << "Student not found.\n";
}

void Professor::displayStudents()
{
    for (const auto &student : usersData["students"])
    {
        if (student.contains("id") && student.contains("username"))
        {
            int id = student["id"];
            std::string name = student["username"];
            std::cout << "Student ID: " << id << ", Name: " << name << "\n";
            if (student.contains("grades") && !student["grades"].is_null())
            {
                for (const auto &[subject, grade] : student["grades"].items())
                {
                    std::cout << subject << ": " << grade << "\n";
                }
            }
            else
            {
                std::cout << "No grades available.\n";
            }
            std::cout << "----------------------\n";
        }
    }
}