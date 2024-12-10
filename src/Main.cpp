#include <iostream>
#include "../include/UserManager.hpp"
#include "../include/GradeManager.hpp"

int main() {
    UserManager userManager("db.json");
    GradeManager gradeManager;

    // Login or Sign-In
    std::string username, password, role;
    std::cout << "Role (student/professor): ";
    std::cin >> role;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    if (!userManager.login(username, password, role)) {
        std::cout << "Login failed. Do you want to sign up? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice == 'y') {
            userManager.signIn(username, password, role);
        } else {
            return 0;
        }
    }

    // Example: Add grades for a student
    if (role == "professor") {
        gradeManager.addStudent(username);
        gradeManager.addGrade(username, 90);
        gradeManager.addGrade(username, 85);
    }

    return 0;
}
