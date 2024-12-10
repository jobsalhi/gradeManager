#ifndef USERMANAGER_HPP
#define USERMANAGER_HPP

#include <string>
#include "../Lib/nlohmann/json.hpp" // JSON handling library

class UserManager {
private:
    nlohmann::json usersData; // JSON object to store user data
    std::string filePath; // Path to the JSON file

    void loadUsers();  // Load user data from JSON file
    void saveUsers();  // Save user data to JSON file

public:
    UserManager(const std::string& path); // Constructor
    bool signIn(const std::string& username, const std::string& password, const std::string& role);
    bool login(const std::string& username, const std::string& password, const std::string& role);
};

#endif // USERMANAGER_HPP
