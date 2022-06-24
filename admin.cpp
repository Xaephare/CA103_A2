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
        
        string toCSV = admin.ID + "," + admin.firstName + "," + admin.lastName;
        ::writeCsv("data/admin_data.csv", toCSV);

    }

    void loadAdminCSV(string filename, string ID){
        string data = "ID not found\n";
        std::vector<std::string> dataVector = CSVtoVector(filename, ID);
        admin.ID = dataVector[0];
        admin.firstName = dataVector[1];
        admin.lastName = dataVector[2];
    }

// int main() {
//     admin test;
// 	test.newAdmin();
// 	cout << "\nTesting completed successfully";

// 	return 0;
// }
