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
//
//    
//    customer(){
//        ID = firstName = lastName =  "null";
//    }

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
        cout << "Phone number: ";
        cin >> admin.phone;
        registerNewUser(admin.ID);
        
        std::string toCSV = admin.ID + "," + admin.firstName + "," + admin.lastName;
        writeCsv("data/admin_data.csv", toCSV);

    }

    Admin loadAdmin(std::string filename, std::string ID){
           std::vector<std::string> dataVector = CSVtoVector(filename, ID);

        if (dataVector.size() == 1) {
            admin.ID = dataVector[0];
        }
        else {
            admin.ID = dataVector[0];
            admin.firstName = dataVector[1];
            admin.lastName = dataVector[2];
            admin.phone = dataVector[3];
        }

        return admin;
    }
    
    
    void customerMenu(Login session){
        Policy vehicleID;
        admin.userLoginInfo.email = session.email;
        int menuSelection = 0;
        cout << "\nWelcome " << admin.firstName;
        cout << "\nPlease select from the following options: ";
        cout << "\n1. View a customer's details.";
        cout << "\n2. Update a customer's details.";
        cout << "\n3. View pending claims.";
        cin >> menuSelection;
        switch (menuSelection) {
	        case 1: 
		        //Customer print statement to be print printCustomer()

                printCustomer();
		        break;
	        case 2:
                updateCsv("data/customer_data.csv", customer.ID);
		        //Update customer info 
		        break;
	        case 3:
                loadPolicy("data/policy_data.csv", customer.ID);
                printPolicy();
		        //Print function from policy.cpp
		        break;
	        case 4:
                vehicleID = loadPolicy("data/policy_data.csv", customer.ID);
                loadVehicle("data/vehicle_data.csv", vehicleID.insuredVehicle.ID);
                printVehicle();
                //Print function from vehicle.cpp
                break;
            case 5: 
                //Print function from claim.cpp - will also need logic to say if a claim exists or not
                break;
            case 6: 
                openingMenu();
                break;
            default:
                cout << "Please pick from one of the displayed options by pressing their respective number.";
                break;
            }
    }

// int main() {
//     admin test;
// 	test.newAdmin();
// 	cout << "\nTesting completed successfully";

// 	return 0;
// }
