#pragma once

#include "user.h"
#include "Moderator.h"
#include "Admin.h"
#include <vector>
#include <string>

class UserStore
{
public:
    UserStore();

    int getSize();

    void addUser(User *user);
    void initUsers();
    void printUsers();
    void printUsersForUser();
    void deleteById(size_t index);

    UserStore* getStore();
    User* get(size_t index);
    User* authorizateUser(std::string login, std::string password);
private:
    std::vector<User* > users;
};