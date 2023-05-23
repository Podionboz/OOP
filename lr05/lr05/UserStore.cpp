#include "UserStore.h"
#include <iostream>

UserStore* store2 = nullptr;

UserStore::UserStore() {
    this->users = {};
};

int UserStore::getSize() {
    return this->users.size();
}

User* UserStore::get(size_t index) {
    return this->users[index];
}

void UserStore::addUser(User *user) {
    this->users.push_back(user);
}

void UserStore::initUsers() {
    UserStore* store = new UserStore();

    store->addUser(new User("User-test", "User-test", "user-test", "test01"));
    store->addUser(new User("User-test2", "User-test2", "user-test2", "test02"));

    store->addUser(new Moderator("Moderator-test", "Moderator-test", "moderator-test", "mtest"));

    store->addUser(new Admin("Rodion", "Bozhok", "rodya", "123"));

    store2 = store;
}

void UserStore::printUsers() {
    int length = getStore()->getSize();

    for (size_t index = 0; index < length; index++) {
        User* user = getStore()->get(index);
        std::cout << "Id: " << user->getId() << std::endl;
        std::cout << "First Name: " << user->getFName() << std::endl;
        std::cout << "Last Name: " << user->getLname() << std::endl;
        std::cout << "Login: " << user->getLogin() << std::endl;
        std::cout << "Password: " << user->getPassword() << std::endl;
        std::cout << "role: " << user->getRole() << std::endl;
        std::cout << "---------------------------------------------------------" << std::endl;
    }
}

void UserStore::printUsersForUser() {
    int length = getStore()->getSize();

    for (size_t index = 0; index < length; index++) {
        User* user = getStore()->get(index);
        std::cout << "First Name: " << user->getFName() << std::endl;
        std::cout << "Last Name: " << user->getLname() << std::endl;
        std::cout << "Login: " << user->getLogin() << std::endl;
        std::cout << "role: " << user->getRole() << std::endl;
        std::cout << "---------------------------------------------------------" << std::endl;
    }
}

void UserStore::deleteById(size_t index) {
    this->users.erase(this->users.begin() + index);
}

UserStore* UserStore::getStore() {
    return store2;
}

User* UserStore::authorizateUser(std::string login, std::string password)
{
    int length = getStore()->getSize();

    for (size_t index = 0; index < length; index++) {
        User* user = getStore()->get(index);
        if(user->getLogin() == login) {
            if (user->getPassword() == password) {
                std::cout << "Authorizate success" << std::endl;
                system("PAUSE");
                return user;
            }
            else {
                std::cout << "Password fail" << std::endl;
                system("PAUSE");
                return nullptr;
            }
        }
    }
    std::cout << "Login fail" << std::endl;
    system("PAUSE");
    return nullptr;
}
