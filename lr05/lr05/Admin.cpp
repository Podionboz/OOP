#include "Admin.h"
#include <iostream>

Admin::Admin(std::string firstName, std::string lastName, std::string login, std::string password) : User(firstName, lastName, login, password) {
	this->role = "admin";
}

void Admin::deleteUser() {
	UserStore* store = nullptr;
	store = store->getStore();
	int userID, length = store->getStore()->getSize();
	
	std::cout << "Enter user ID: ";
	std::cin >> userID;

	for (size_t index = 0; index < length; index++)
	{
		if (store->get(index)->getId() == userID)
		{
			store->deleteById(index);
			break;
		}
	}
}