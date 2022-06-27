//Import filemanager.cpp
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include "header.h"
using namespace std;

//using std::cout;
//using std::cin;
//using std::string; 


struct Vehicle vehicle;
//struct vehicle{
//	int id,
//        insuredValue;
//    string registration,
//        make,
//	    model,
//	    colour;
//    
//
//    vehicle(){
//        id = insuredValue = 0;
//        registration = make = model = colour = "unassigned";
//    } 
//    //int year;
//	//int doors{};
//	//string transmission{}
//};

string fetchVehicleIDNum() {
    int ID = readTxt("data/vehicle_id_counter.txt");
    writeTxt("data/vehicle_id_counter.txt", ID);
    string stringID = std::to_string(ID);
    return stringID;
}


void printVehicle() {
    cout << "\n";
    cout << "   VEHICLE INFORMATION FOR: " << vehicle.ID << "\n";
    cout << "   ---------------------------------- \n";
    cout << "   Vehicle Registration:  " << vehicle.registration << "\n";
    cout << "   Make:                  " << vehicle.make << "\n";
    cout << "   Model:                 " << vehicle.model << "\n";
    cout << "   Colour:                " << vehicle.colour << "\n";
    cout << "   Insured Value:         $" << vehicle.insuredValue << "\n";
    cout << "   ---------------------------------- \n";

}

void getInsuranceValue() {
    bool valid = true;
    int insuredValue = 0;
    cout << "Enter insured value: ";
    cin >> insuredValue;
    while (valid) {
        while (cin.fail()) { //catches non int entries
            cout << "Please enter a valid value.\n";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cin >> insuredValue;
        }
        if (insuredValue > 0 && insuredValue < 1000000) {
            vehicle.insuredValue = insuredValue;
            valid = false;
        }
    }
}

Vehicle getVehicleInfo(string ID) {
    string insuredValueStr;
    vehicle.ID = ID;
    cout << "Please input vehicle information \n";
    cout << "Enter registration: \n";
    cin >> vehicle.registration;
    cout << "Enter make: ";
    cin >> vehicle.make;
    cout << "Enter model: ";
    cin >> vehicle.model;
    cout << "Enter colour: ";
    cin >> vehicle.colour;
    getInsuranceValue();

    insuredValueStr = std::to_string(vehicle.insuredValue);
    string toCSV = vehicle.ID + "," + vehicle.registration + "," + vehicle.make + "," + vehicle.model + "," + vehicle.colour + "," + insuredValueStr;
    ::writeCsv("data/vehicle_data.csv", toCSV);
    cout << toCSV;

    return vehicle;
}

Vehicle loadVehicle(string filename, string ID) {
    std::vector<std::string> dataVector = CSVtoVector(filename, ID);

    if (dataVector.size() == 1) {
        vehicle.ID = dataVector[0];
    }
    else {
        vehicle.ID = dataVector[0];
        vehicle.registration = dataVector[1];
        vehicle.make = dataVector[2];
        vehicle.model = dataVector[3];
        vehicle.colour = dataVector[4];
        vehicle.insuredValue = stoi(dataVector[5]);
    }

    if (dataVector[0] == "none") {
        cout << "not found";
    }
    else {
        return vehicle;
    }
}


// int main() {
//     getVehicleInfo("2000"); 
//     printVehicle();
//     return 0;
// }
