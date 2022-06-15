
#include <iostream>
using std::cout;
using std::cin;
using std::string;


void mainMenu() {
	int choice = 0;

	cout << "\n------------------------------------------------";
	cout << "\nAdmin controls";
	cout << "\nPending applications: " << "(displays number of pending applications)";
	cout << "\n------------------------------------------------";
	cout << "\n\n1 - View/approve insurance applications";
	cout << "\n2 - View/approve claim requests";
	cout << "\n3 - View/edit client information";
	cout << "\n4 - Create a new admin account";
	cout << "\n5 - Exit program\n";

	choice:
	cout << "\nPick an option: ";
	cin >> choice;
	switch (choice) {
	case 1: cout << "view all pending applications. then choose whether to approve or deny";
		break;
	case 2: cout << "input client number to receive all their claim requests. choose whether to approve or deny.";
		break;
	case 3: cout << "input client number to view/edit their info";
		break;
	case 4: cout << "create new account that is an admin one";
	case 5: break;
	default: cout << "Please pick one of the displayed options by pressing their respective number.";
		goto choice;
	}
}

int main() {

	mainMenu();

	return 0;
}