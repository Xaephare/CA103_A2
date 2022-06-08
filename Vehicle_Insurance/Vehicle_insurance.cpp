#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;


/*void mainMenu() {
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

	};
};*/
	


struct vehicleInfo {
	int id{};
	string make{};
	string model{};
	int year{};
	string colour{};
	int doors{};
	string transmission{};


};
vector<vehicleInfo> cars = {};

void vehicleData() {

	int id{};
	vehicleInfo car = {};
	cout << "Please enter the make of vehicle: \n";
	cin >> car.make;
	cout << "Please enter the model of vehicle: \n";
	cin >> car.model;
	cout << "Please enter year of vehicle: \n";
	cin >> car.year;
	cout << "Please enter colour of vehicle: \n";
	cin >> car.colour;
	cout << "Please enter how many doors the vehicle has - include the rear / boot as 1 door: \n";
	cin >> car.doors;
	cout << "Please enter transmission type of vehicle: \n";
	cin >> car.transmission;
	cars.push_back(car);
};

void printVehicle() {

	int id{};
	for (auto i = cars.begin(); i != cars.end(); i++) {
		vehicleInfo car = *i;

		cout << endl;
		cout << endl;
		cout << "Make: " << car.make << endl;
		cout << "Model: " << car.model << endl;
		cout << "Year: " << car.year << endl;
		cout << "Colour: " << car.colour << endl;
		cout << "Doors: " << car.doors << " Doors" << endl;
		cout << "Transmission: " << car.transmission << endl;
		std::ofstream vehicleDb;
		vehicleDb.open("vehicleDb.json");
		vehicleDb << "Make: " << car.make << "\n" << "Model: " << car.model << "\n" << "Year: " << car.year << "\n" << "Colour: " << car.colour << "\n" << "Doors: " << car.doors << " Doors\n" << "Transmission: " << car.transmission << "\n";
		vehicleDb.close();
	};
};

int main() {
	//mainMenu();
	printVehicle();
	vehicleData();
	

	
	return 0;
}