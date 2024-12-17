#include "User.hpp"
#include <fstream>
#include <iostream>

User::User(const std::string& dbPath) : dbPath(dbPath) {
    loadUsers();
}

void User::loadUsers() {
    std::ifstream file(dbPath);
    if (file.is_open()) {
        file >> usersData;
        file.close();
    }
}

void User::saveUsers() const {
    std::ofstream file(dbPath);
    if (file.is_open()) {
        file << usersData.dump(4);
        file.close();
    }
}

bool User::signIn(const std::string& username, const std::string& password, const std::string& role) {
    if (role == "student") {
        for (const auto& student : usersData["students"]) {
            if (student["username"] == username) {
                std::cout << "Username already exists.\n";
                return false;
            }
        }
        usersData["students"].push_back({{"username", username}, {"password", password}, {"grades", {}}});
    } else if (role == "professor") {
        for (const auto& professor : usersData["professors"]) {
            if (professor["username"] == username) {
                std::cout << "Username already exists.\n";
                return false;
            }
        }
        usersData["professors"].push_back({{"username", username}, {"password", password}});
    }
    saveUsers();
    return true;
}

int User::login(const std::string& username, const std::string& password, const std::string& role) {
    if (role == "student") {
        for (const auto& student : usersData["students"]) {
            if (student["username"] == username && student["password"] == password) {
                std::cout << "Login successful.\n";
                return student["id"];
            }
        }
    } else if (role == "professor") {
        for (const auto& professor : usersData["professors"]) {
            if (professor["username"] == username && professor["password"] == password) {
                std::cout << "Login successful.\n";
                return professor["id"];
            }
        }
    }
    std::cout << "Invalid credentials.\n";
    return -1;
}

nlohmann::json User::getUsersData() const {
    return usersData;
}