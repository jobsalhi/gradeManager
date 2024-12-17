#include <iostream>
#include "Student.hpp"
#include "Professor.hpp"
#include "GradeManager.hpp"

int main() {
    std::string dbPath = "db.json";
    std::string role;
    std::cout << "Are you a student or a professor? ";
    std::cin >> role;

    if (role == "student") {
        Student student(dbPath);
        std::string username, password;
        std::cout << "Do you want to sign up or login? (signup/login): ";
        std::string action;
        std::cin >> action;

        int userId = -1;
        if (action == "signup") {
            std::cout << "Username: ";
            std::cin >> username;
            std::cout << "Password: ";
            std::cin >> password;
            if (student.signIn(username, password, role)) {
                userId = student.login(username, password, role);
            } else {
                return 0;
            }
        } else if (action == "login") {
            std::cout << "Username: ";
            std::cin >> username;
            std::cout << "Password: ";
            std::cin >> password;
            userId = student.login(username, password, role);
        }

        if (userId != -1) {
            std::vector<int> grades = student.getGrades(userId);
            std::cout << "Your grades: ";
            for (int grade : grades) {
                std::cout << grade << " ";
            }
            std::cout << "\nYour average grade: " << student.calculateAverage(userId) << "\n";
        }
    } else if (role == "professor") {
        Professor professor(dbPath);
        std::string username, password;
        std::cout << "Do you want to sign up or login? (signup/login): ";
        std::string action;
        std::cin >> action;

        int userId = -1;
        if (action == "signup") {
            std::cout << "Username: ";
            std::cin >> username;
            std::cout << "Password: ";
            std::cin >> password;
            if (professor.signIn(username, password, role)) {
                userId = professor.login(username, password, role);
            } else {
                return 0;
            }
        } else if (action == "login") {
            std::cout << "Username: ";
            std::cin >> username;
            std::cout << "Password: ";
            std::cin >> password;
            userId = professor.login(username, password, role);
        }

        if (userId != -1) {
            int studentId;
            std::cout << "Enter student ID to add or modify grades: ";
            std::cin >> studentId;
            std::cout << "Enter student name: ";
            std::string studentName;
            std::cin >> studentName;
            professor.addStudent(studentId, studentName);

            std::vector<int> grades;
            std::cout << "Enter grades (separated by space, end with -1): ";
            int grade;
            while (std::cin >> grade && grade != -1) {
                grades.push_back(grade);
            }
            professor.modifyGrades(studentId, grades);
        }
    }

    return 0;
}