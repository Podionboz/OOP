#pragma once
#include "User.h"
#include "UserStore.h"

class Moderator :
    public User
{
public:
    Moderator(std::string firstName, std::string lastName, std::string login, std::string password);

    void editUser();
};

