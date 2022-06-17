//Import filemanager.cpp
#include <iostream>
#include <vector>
#include <string>

#include "header.h"

using std::cout;
using std::cin;
using std::string; 


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


    void printVehicle(){
        cout << "\n";
        cout << "   VEHICLE INFORMATION FOR: " << vehicle.id << "\n";
        cout << "   ---------------------------------- \n";
        cout << "   Vehicle Registration:  " << vehicle.registration << "\n";
        cout << "   Make:                  " << vehicle.make << "\n";
        cout << "   Model:                 " << vehicle.model << "\n";
        cout << "   Colour:                " << vehicle.colour << "\n";
        cout << "   Insured Value:         $" << vehicle.insuredValue << "\n";
        cout << "   ---------------------------------- \n";

    }

    void getVehicleInfo(){
        // unique id to be generated once filemanager.cpp built
        cout << "Please input vehicle information \n";
        cout << "Enter registration: ";
        getline(cin, vehicle.registration);
        cout << "Enter make: ";
        getline(cin, vehicle.make);
        cout << "Enter model: ";
        getline(cin, vehicle.model);
        cout << "Enter colour: ";
        getline(cin, vehicle.colour);
        cout << "Enter insured value: " ;
        cin >> vehicle.insuredValue;
            while (vehicle.insuredValue <= 1 || vehicle.insuredValue >= 100000){
                cout << "Invalid value. Insured value must be more than $0 and less than $100000\n";
                cin >> vehicle.insuredValue;
            }

    }


int main() {
    getVehicleInfo(); 
    printVehicle();
    return 0;
}