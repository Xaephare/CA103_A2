
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::string;
 
 #include "header.h"


// Customer Menu
void customerOpeningMenu(){
	int menuSelection;
	Login sessionID;
	Customer currentCust;
	cout << "\n------------------------------------------------";
	cout << "\n			CUSTOMER MENU";
	cout << "\n------------------------------------------------";
	cout << "\n\n		1. I already have an account.";
	cout << "\n		2. I would like to create an account.";
	cout << "\n		3. Return to Main Menu";
	cout << "\n		4. Exit.\n";
	cin >> menuSelection;
	switch (menuSelection) {
	case 1:
		sessionID = checkLogin();
		currentCust = loadCustomer("data/customer_data.csv", sessionID.userID);
		customerMenu(sessionID);
		// Logic so customerMenu opens if checkLogin successful.
		// customerMenu(bool LoginSuccesful)
		break;
	case 2:
		newCustomer();  //called from customer.cpp and login.cpp
		break;
	case 3: 
		openingMenu();
		break;
	case 4: 
	cout << "Goodbye!\n";
	break;
	default: cout << "Please pick from one of the displayed options by pressing their respective number.";
	}
}

// Admin Login Menu
void adminOpeningMenu(){
	int menuSelection;
	Login sessionID;
	Admin currentAdmin;
	cout << "\n------------------------------------------------";
	cout << "\n			ADMIN MENU";
	cout << "\n------------------------------------------------";
	cout << "\n\n		1. I already have an account.";
	cout << "\n		2. I would like to create an account.";
	cout << "\n		3. Return to Main Menu";
	cout << "\n		4. Exit.\n";
	cin >> menuSelection;
		switch (menuSelection) {
	case 1: 
		sessionID = checkLogin();
		currentAdmin = loadAdmin("data/admin_data.csv", sessionID.userID);
		adminMenu(sessionID);
		break;
	case 2:
		newAdmin();  //called from customer.cpp and login.cpp
		break;
	case 3: 
		openingMenu();
		break;
	case 4: 
	cout << "Goodbye!\n";
	break;
	default: cout << "Please pick from one of the displayed options by pressing their respective number.";
	}
}

void openingMenu() {
	int menuSelection;
	Login sessionID;
	cout << "\n------------------------------------------------";
	cout << "\n	Welcome to EPIC Vehicle Insurance";
	cout << "\n------------------------------------------------";
	cout << "\n	Please select from the User options below. ";
	cout << "\n\n		1. I am a Customer.";
	cout << "\n		2. I am an Administrator.";
	cout << "\n		3. Exit.\n";
	cin >> menuSelection;
	switch (menuSelection) {
	case 1: 
		customerOpeningMenu();
		break;
	case 2:
		adminOpeningMenu();
		break;
	case 3: 
		cout << "Goodbye!\n";
	break;
	default: cout << "Please pick from one of the displayed options by pressing their respective number.";
	}
}

int main() {

	openingMenu();

	return 0;
}
