#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "User.h"
#include "Moderator.h"
#include "Admin.h"
#include "UserStore.h"

UserStore* store;
User* users;
Moderator* moderator;
Admin* admin;

int main() {
    store->initUsers();

    std::string login, password;

    char choose;
    do {
        system("CLS");
        std::cout << "Login: ";
        std::cin >> login;
        std::cout << "Password: ";
        std::cin >> password;

        users = store->authorizateUser(login, password);
    } while (users == NULL);
    std::cout << "Your info:" << std::endl;

    if (users->getRole() == "user") {
        system("CLS");

        std::cout << "First name: " << users->getFName() << std::endl;
        std::cout << "Last Name: " << users->getLname() << std::endl;
        std::cout << "Login: " << users->getLogin() << std::endl;
        std::cout << "Password: " << users->getPassword() << std::endl;
        std::cout << "role: " << users->getRole() << std::endl;
        std::cout << "==============================================================================" << std::endl;
        std::cout << "View all users? (Y/N): ";
        do {
            choose = _getch();
        } while (choose != 'Y' && choose != 'N');
        if (choose == 'Y') {
            system("CLS");
            std::cout << "==============================================================================" << std::endl;
            std::cout << "\t\t\tAll users" << std::endl;
            std::cout << "==============================================================================" << std::endl;
            store->printUsersForUser();
        }
        else
            return 0;
    }

    if (users->getRole() == "moderator") {
        do {
            system("CLS");

            std::cout << "First name: " << users->getFName() << std::endl;
            std::cout << "Last Name: " << users->getLname() << std::endl;
            std::cout << "Login: " << users->getLogin() << std::endl;
            std::cout << "Password: " << users->getPassword() << std::endl;
            std::cout << "role: " << users->getRole() << std::endl;
            std::cout << "==============================================================================" << std::endl;
            std::cout << "1. View all users\n2. Edit information about user\nExit (ESC)" << std::endl;
            choose = _getch();

            if (choose == '1') {
                system("CLS");
                store->printUsers();
                system("PAUSE");
            }

            else if (choose == '2') {
                system("CLS");
                store->printUsers();
                std::cout << "==============================================================================" << std::endl;
                moderator->editUser();
                system("CLS");
                store->printUsers();
                system("PAUSE");
            }
        } while (choose != 27);
    }

    if (users->getRole() == "admin") {
        do {
            system("CLS");

            std::cout << "First name: " << users->getFName() << std::endl;
            std::cout << "Last Name: " << users->getLname() << std::endl;
            std::cout << "Login: " << users->getLogin() << std::endl;
            std::cout << "Password: " << users->getPassword() << std::endl;
            std::cout << "role: " << users->getRole() << std::endl;
            std::cout << "==============================================================================" << std::endl;
            std::cout << "1. View all users\n2. Edit information about user\n3. Delete user by ID\nExit (ESC)" << std::endl;
            choose = _getch();

            if (choose == '1') {
                system("CLS");
                store->printUsers();
                system("PAUSE");
            }

            else if (choose == '2') {
                system("CLS");
                store->printUsers();
                std::cout << "==============================================================================" << std::endl;
                moderator->editUser();
                system("CLS");
                store->printUsers();
                system("PAUSE");
            }

            else if (choose == '3') {
                system("CLS");
                store->printUsers();
                std::cout << "==============================================================================" << std::endl;
                admin->deleteUser();
                system("CLS");
                store->printUsers();
                system("PAUSE");
            }
        } while (choose != 27);
    }
    system("PAUSE");
    return 0;
}
