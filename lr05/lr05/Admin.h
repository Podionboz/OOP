#pragma once
#include "User.h"
#include "UserStore.h"

class Admin :
    public User
{
public:
    Admin(std::string firstName, std::string lastName, std::string login, std::string password);

    void deleteUser();
};

