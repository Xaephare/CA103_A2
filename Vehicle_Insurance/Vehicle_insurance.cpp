#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using std::string;
using std::vector;
using std::cin;
using std::cout;
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
	//int id{};
	string make = "null";
	string model = "null";
	int year =0;
	string colour = "null";
	int doors = 0;
	string transmission = "null";


};
vector<vehicleInfo> cars;

void vehicleData() {

//	int id{};
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

	//	int id{};
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
	};
}

bool writeCsv(string fileName, string make, string model, int year, string colour, int doors, string transmission) {


	std::ofstream file;
	file.open(fileName, std::ios_base::app);
	file << make << "," << model << "," << year << "," << colour << "," << doors << transmission << endl;
	file.close();

	return true;
};




int main() {
	//mainMenu();
	printVehicle();
	vehicleData();
	
	writeCsv("data/vehicleDb.csv", cars[0].make, cars[0].model, cars[0].year, cars[0].colour, cars[0].doors, cars[0].transmission);

	
	return 0;
}