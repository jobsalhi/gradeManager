#pragma once
#include <string>
#include "../Lib/nlohmann/json.hpp" 

class User {
public:
    User(const std::string& dbPath);
    virtual ~User() = default;
    bool signIn(const std::string& username, const std::string& password, const std::string& role);
    int login(const std::string& username, const std::string& password, const std::string& role);
    nlohmann::json getUsersData() const;
    void saveUsers() const;

protected:
    std::string dbPath;
    nlohmann::json usersData;
    void loadUsers();
};