//Import filemanager.cpp
#include <iostream>
#include <vector>
#include <string>

#include "header.h"
<<<<<<< HEAD
=======
//#include "TEST_filemanager.h" // Header not working - Filemanager working as test
>>>>>>> 0b99a08 (Vehicle with ID, and Read/write functions. )

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

    string fetchVehicleIDNum() { 
        int ID = readTxt("data/vehicle_id_counter.txt");
        writeTxt("data/vehicle_id_counter.txt", ID);
        string stringID = std::to_string(ID);
        return stringID;
    }


    void printVehicle(){
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

    void getVehicleInfo(string ID){
        vehicle.ID = fetchVehicleIDNum();
        string insuredValueStr;
        cout << "Please input vehicle information \n";
        cout << "Enter registration: \n";
        cin >> vehicle.registration;
        cout << "Enter make: ";
        cin >> vehicle.make;
        cout << "Enter model: ";
        cin >> vehicle.model;
        cout << "Enter colour: ";
        cin >> vehicle.colour;
        cout << "Enter insured value: " ;
        cin >> vehicle.insuredValue;
            while (vehicle.insuredValue <= 1 || vehicle.insuredValue >= 100000){
                cout << "Invalid value. Insured value must be more than $0 and less than $100000\n";
                cin >> vehicle.insuredValue;
               // insuredValueStr = std::to_string(vehicle.insuredValue);
            }
            insuredValueStr = std::to_string(vehicle.insuredValue);
            
            string toCSV = vehicle.ID + "," + vehicle.registration + "," + vehicle.make + "," + vehicle.model + "," + vehicle.colour + "," + insuredValueStr;
            ::writeCsv("data/vehicle_data.csv", toCSV); 
            cout << toCSV;
    }


// int main() {
//     getVehicleInfo("2000"); 
//     printVehicle();
//     return 0;
// }
