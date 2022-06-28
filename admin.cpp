#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <string.h>

#include "header.h"


using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

struct Admin admin;
//struct customer {
//    login userLoginInfo;
//	string ID; 
//	string firstName,
//	    lastName,

string fetchAdminNum() {
	int ID = readTxt("data/admin_id_counter.txt");
	writeTxt("data/admin_id_counter.txt", ID);
	string stringID = std::to_string(ID);
	return stringID;
}

void newAdmin() {
	admin.ID = fetchAdminNum();
	cout << "Your Admin ID number is: " << admin.ID << "\n";
	cout << "First Name: ";
	cin >> admin.firstName;
	cout << "Last name: ";
	cin >> admin.lastName;
	registerNewUser(admin.ID);

	std::string toCSV = admin.ID + "," + admin.firstName + "," + admin.lastName;
	writeCsv("data/admin_data.csv", toCSV);

}

Admin loadAdmin(std::string filename, std::string ID) {
	std::vector<std::string> dataVector = CSVtoVector(filename, ID);

	if (dataVector.size() == 1) {
		admin.ID = dataVector[0];
	}
	else {
		admin.ID = dataVector[0];
		admin.firstName = dataVector[1];
		admin.lastName = dataVector[2];
	}

	return admin;
}


void adminMenu(Login session) {  // Login session
	string viewCustomerID;
	Customer selectedCustomer;
	int menuSelection = 0;
	bool menuRunning = true;
	while (menuRunning) {
		cout << "\nWelcome " << admin.firstName;
		cout << "\nPlease select from the following options: ";
		cout << "\n1. View a customer's details.";
		cout << "\n2. Update a customer's details.";
		cout << "\n3. View/Approve a claim.";
		cout << "\n4. Log out.\n";
		cin >> menuSelection;
		cout << std::endl;

		switch (menuSelection) {
		case 1:
			cout << "Please enter the ID number of the customer you would like to view: ";
			cin >> viewCustomerID;
			selectedCustomer = loadCustomer("data/customer_data.csv", viewCustomerID);
			loadLogin("data/login_data.csv", viewCustomerID);
			printCustomer(); //further debugging needed, when admin calls this it does not print customer email.
			break;
		case 2:
			cout << "Please enter the ID number of the customer you would like to update the details: ";
			cin >> viewCustomerID;
			updateCsv("data/customer_data.csv", viewCustomerID);
			break;
		case 3:
			cout << "Please enter the ID number of the client whose claim you would like to edit: ";
			cin >> viewCustomerID;
			loadClaim("data/claim_data.csv", viewCustomerID);
			printClaim();

			char choice;
			cout << "Do you want to approve this claim? (Y/n): ";
			cin >> choice;
			if (choice == 'y' || choice == 'Y') {
				updateClaim("data/claim_data.csv", viewCustomerID);
			}
			else {
				cout << "---------------------------------- \n";
				cout << "Claim was not approved.\n";
				cout << "---------------------------------- \n";
			}
			break;
		case 4:
			menuRunning = false;
			openingMenu();
			break;
		default:
			cout << "Please pick from one of the displayed options by pressing their respective number.";
			break;
		}
	}
}