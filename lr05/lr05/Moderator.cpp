#include <iostream>
#include <conio.h>
#include <string>
#include "Moderator.h"

Moderator::Moderator(std::string firstName, std::string lastName, std::string login, std::string password) : User(firstName, lastName, login, password) {
	this->role = "moderator";
}

void Moderator::editUser() {
	UserStore* store = nullptr; store = store->getStore();

	int userID, length = store->getStore()->getSize();
	char choose;
	std::string newValue;

	std::cout << "Enter user ID: ";
	std::cin >> userID;

	for (size_t index = 0; index < length; index++)
	{
		if (index > userID)
			break;
		else if (store->get(index)->getId() == userID && store->get(index)->getRole() != "admin") {
			do {
			std::cout << "What do you want to change?\n1. First Name\n2. Last Name\n3. Login\n4. Password\n5. Change to moderator\n6. Change to user\nYour choose: ";
				choose = _getch();
			} while (choose < '1' || choose > '6');
			system("CLS");
			switch (choose) {
			case '1':
				std::cout << "Enter a new value: ";
				std::cin >> newValue;
				store->get(index)->setFName(newValue);
				break;
			case '2':
				std::cout << "Enter a new value: ";
				std::cin >> newValue;
				store->get(index)->setLName(newValue);
				break;
			case '3':
				std::cout << "Enter a new value: ";
				std::cin >> newValue;
				store->get(index)->setLogin(newValue);
				break;
			case '4':
				std::cout << "Enter a new value: ";
				std::cin >> newValue;
				store->get(index)->setPassword(newValue);
				break;
			case '5':
				if (store->get(index)->getRole() == "moderator") {
					std::cout << "This user is already moderator!" << std::endl;
					system("PAUSE");
					break;
				}
				newValue = "moderator";
				store->get(index)->setRole(newValue);
				std::cout << "Success!" << std::endl;
				system("PAUSE");
				break;
			case '6':
				if (store->get(index)->getRole() == "user") {
					std::cout << "It is already user!" << std::endl;
					system("PAUSE");
					break;
				}
				newValue = "user";
				store->get(index)->setRole(newValue);
				std::cout << "Success!" << std::endl;
				system("PAUSE");
				break;
			default:
				break;
			}
		}
		else if(store->get(index)->getRole() == "admin") {
			std::cout << "You cannot edit the admin!" << std::endl;
			system("PAUSE");
		}
	}
}