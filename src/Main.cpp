#include <iostream>
#include "Student.hpp"
#include "Professor.hpp"
#include "GradeManager.hpp"

int main()
{
    std::string dbPath = "db.json";
    std::string role;
    std::cout << "Are you a student or a professor? ";
    std::cin >> role;

    if (role == "student")
    {
        Student student(dbPath);
        std::string username, password;
        std::cout << "Do you want to sign up or login? (signup/login): ";
        std::string action;
        std::cin >> action;

        int userId = -1;
        if (action == "signup")
        {
            std::cout << "Username: ";
            std::cin >> username;
            std::cout << "Password: ";
            std::cin >> password;
            if (student.signIn(username, password, role))
            {
                userId = student.login(username, password, role);
            }
            else
            {
                return 0;
            }
        }
        else if (action == "login")
        {
            std::cout << "Username: ";
            std::cin >> username;
            std::cout << "Password: ";
            std::cin >> password;
            userId = student.login(username, password, role);
        }

        if (userId != -1)
        {
            while (true)
            {
                std::cout << "Choose an option: (1) See grades (2) Calculate average (3) Quit: ";
                int option;
                std::cin >> option;

                if (option == 1)
                {
                    auto grades = student.getGrades(userId);
                    std::cout << "Your grades:\n";
                    for (const auto &[subject, grade] : grades)
                    {
                        std::cout << subject << ": " << grade << "\n";
                    }
                }
                else if (option == 2)
                {
                    std::cout << "Your average grade: " << student.calculateAverage(userId) << "\n";
                }
                else if (option == 3)
                {
                    break;
                }
                else
                {
                    std::cout << "Invalid option. Please try again.\n";
                }
            }
        }
    }
    else if (role == "professor")
    {
        Professor professor(dbPath);
        std::string username, password;
        std::cout << "Do you want to sign up or login? (signup/login): ";
        std::string action;
        std::cin >> action;

        int userId = -1;
        if (action == "signup")
        {
            std::cout << "Username: ";
            std::cin >> username;
            std::cout << "Password: ";
            std::cin >> password;
            if (professor.signIn(username, password, role))
            {
                userId = professor.login(username, password, role);
            }
            else
            {
                return 0;
            }
        }
        else if (action == "login")
        {
            std::cout << "Username: ";
            std::cin >> username;
            std::cout << "Password: ";
            std::cin >> password;
            userId = professor.login(username, password, role);
        }

        if (userId != -1)
        {
                int option;
            while (true)
            {
                std::cout << "Choose an option: (1) Add a grade (2) Modify a grade (3) Display students and grades (4) Quit: ";
                std::cin >> option;

                if (option == 1)
                {
                    int studentId;
                    std::cout << "Enter student ID to add a grade: ";
                    std::cin >> studentId;

                    std::string subject;
                    int grade;
                    std::cout << "Enter the name of the subject: ";
                    std::cin >> subject;
                    std::cout << "Enter the mark: ";
                    std::cin >> grade;
                    professor.addGrade(studentId, subject, grade);
                }
                else if (option == 2)
                {
                    int studentId;
                    std::cout << "Enter student ID to modify a grade: ";
                    std::cin >> studentId;
                    std::string subject;
                    int grade;

                    std::cout << "Enter the name of the subject: ";

                    std::cin >> subject;

                    std::cout << "Enter the new grade: ";

                    std::cin >> grade;

                    professor.modifyGrade(studentId, subject, grade);
                }

                else if (option == 3)
                {
                    professor.displayStudents();
                }
                else if (option == 4)
                {
                    break;
                }
                else
                {
                    std::cout << "Invalid option. Please try again.\n";
                }
            }
        }
    }

    return 0;
}