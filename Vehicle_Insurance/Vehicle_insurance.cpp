#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>


using std::string;
using std::ifstream;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

struct vehicleInfo {
	int id =0;
	int insuredValue =0;
	string registration = "null";
	string make = "null";
	string model = "null";
	int year =0;
	string colour = "null";
	int doors =0;
	string transmission = "null";

};

void read()
{
	ifstream fin{};
	string line;
	// Open an existing file
	fin.open("report.csv");
	while (!fin.eof()) {
		fin >> line;
		cout << line << " ";
	}
}

vector<vehicleInfo> cars;

//int fetchLastVehicleNum() {
//
//	std::ofstream file;
//
//	string numStr;
//	std::fstream vehicleId;
//	vehicleId.open("vehicle_id_counter.txt", std::ios::in);
//	getline(vehicleId, numStr);
//	int vehicleNum = std::stoi(numStr);
//	vehicleId.close();
//
//	return vehicleNum;
//}
//
//void writeTxt(string fileName, int vehicleNumber) {
//	std::fstream file;
//	file.open(fileName, std::ios::out);
//	file << vehicleNumber;
//	file.close();
//}


void vehicleData() { 
	//vehicleInfo addVehic;

	//int lastVehicNum = fetchLastVehicleNum();
	//addVehic.id = ++lastVehicNum;
	//writeTxt("data/vehicle_id_counter.txt", lastVehicNum);

	vehicleInfo car = {};
	cout << "Please enter the registration plate of vehicle: \n";
	cin >> car.registration;
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

	for (auto i = cars.begin(); i != cars.end(); i++) {
		vehicleInfo car = *i;

		cout << endl;
		cout << endl;
		cout << "Registration: " << car.registration << endl;
		cout << "Make: " << car.make << endl;
		cout << "Model: " << car.model << endl;
		cout << "Year: " << car.year << endl;
		cout << "Colour: " << car.colour << endl;
		cout << "Doors: " << car.doors << " Doors" << endl;
		cout << "Transmission: " << car.transmission << endl;
	};
}


void writeCsv(string fileName, int vehicleNum, string registration, string make, string model, int year, string colour, int doors, string transmission) {


	std::ofstream file;

	file.open(fileName, std::ios::out | std::ios_base::app);
	file << "ID" << "," << vehicleNum << "," << "Registration Plate" << "," << registration << "," << "Make" << "," << make << "," << "Model" << "," << model << "," << "Year" << "," << year << "," << "Colour" << "," << colour << "," << "Doors" << "," << doors << "," << "Transmission" << "," << transmission << endl;
	file.close();
};







int main() {
	read();
	printVehicle();
	vehicleData();
	writeCsv("data/vehicleDb.csv", cars[0].id, cars[0].registration, cars[0].make, cars[0].model, cars[0].year, cars[0].colour, cars[0].doors, cars[0].transmission);

	
	return 0;
}