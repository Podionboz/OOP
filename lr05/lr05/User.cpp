#include "User.h"
#include <iostream>

int nid = 0;

User::User(std::string firstName, std::string lastName, std::string login, std::string password) {
    this->id = nid++;
    this->firstName = firstName;
    this->lastName = lastName;
    this->login = login;
    this->password = password;
    this->role = "user";
}

void User::setId(int new_id) {
    this->id = new_id;
}

void User::setFName(std::string new_first_name) {
    this->firstName = new_first_name;
}

void User::setLName(std::string new_last_name) {
    this->lastName = new_last_name;
}

void User::setLogin(std::string new_login) {
    this->login = new_login;
}

void User::setPassword(std::string new_password) {
    this->password = new_password;
}

void User::setRole(std::string new_role) {
    this->role = new_role;
}

int User::getId() {
    return this->id;
}

std::string User::getFName() {
    return this->firstName;
}

std::string User::getLname() {
    return this->lastName;
}

std::string User::getLogin() {
    return this->login;
}

std::string User::getPassword() {
    return this->password;
}

std::string User::getRole() {
    return this->role;
}