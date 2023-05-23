#pragma once
#include <string>

class User
{
public:
    User(std::string firstName, std::string lastName, std::string login, std::string password);
    std::string firstName;
    std::string lastName;
    std::string role;

    void setId(int new_id);
    void setFName(std::string new_first_name);
    void setLName(std::string new_last_name);
    void setLogin(std::string new_login);
    void setPassword(std::string new_password);
    void setRole(std::string new_role);

    int getId();
    std::string getFName();
    std::string getLname();
    std::string getLogin();
    std::string getPassword();
    std::string getRole();
private:
    int id;
    std::string login;
    std::string password;
};