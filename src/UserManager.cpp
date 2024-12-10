#include "../include/UserManager.hpp"
#include <fstream>
#include <iostream>

// Constructor
UserManager::UserManager(const std::string& path) : filePath(path) {
    loadUsers();
}

// Load user data from JSON file
void UserManager::loadUsers() {
    std::ifstream file(filePath);
    if (file.is_open()) {
        file >> usersData;
        file.close();
    } else {
        usersData = {{"students", nlohmann::json::array()}, {"professors", nlohmann::json::array()}};
    }
}

// Save user data to JSON file
void UserManager::saveUsers() {
    std::ofstream file(filePath);
    file << usersData.dump(4); // Pretty-print with 4 spaces
    file.close();
}

// Sign-In method
bool UserManager::signIn(const std::string& username, const std::string& password, const std::string& role) {
    nlohmann::json& userList = (role == "student") ? usersData["students"] : usersData["professors"];
    for (const auto& user : userList) {
        if (user["username"] == username) {
            std::cout << "Username already exists.\n";
            return false;
        }
    }
    userList.push_back({{"username", username}, {"password", password}});
    saveUsers();
    return true;
}

// Login method
bool UserManager::login(const std::string& username, const std::string& password, const std::string& role) {
    const nlohmann::json& userList = (role == "student") ? usersData["students"] : usersData["professors"];
    for (const auto& user : userList) {
        if (user["username"] == username && user["password"] == password) {
            std::cout << "Login successful! Welcome, " << username << ".\n";
            return true;
        }
    }
    return false;
}
