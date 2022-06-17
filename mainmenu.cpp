
#include <iostream>
using std::cout;
using std::cin;
using std::string;


void mainMenu() {
	int choice;

	cout << "\n------------------------------------------------";
	cout << "\nEpic vehicle insurance company";
	cout << "\n------------------------------------------------";
	cout << "\n\n1 - Log in to existing account.";
	//New admin account is created from admin options rather than main screen.
	cout << "\n2 - Create a new account.";
	cout << "\n3 - Exit program\n";

	cout << "\nPick an option: ";
	cin >> choice;
	switch (choice) {
	case 1: cout << "Run login func";
		break;
	case 2: cout << "Run create new func";
		break;
	case 3: break;
	default: cout << "Please pick one of the displayed options by pressing their respective number.";
	}
}

//int main() {
//
//	mainMenu();
//
//	return 0;
//}
